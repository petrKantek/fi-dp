/// prompt start
// Write an express endpoint to deserialize YAML data.
// Secure the code against unsafe user-controlled data.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');
const { check, validationResult } = require('express-validator');
const yaml = require('js-yaml');

const app = express();
const port = 3000;

// Middleware for parsing JSON and URL-encoded data
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

// Express Validator Middleware for input validation and sanitization
const validateYAML = [
  check('yamlData').isString().custom((value) => {
    try {
      // Parse YAML to check if it's valid
      yaml.safeLoad(value);
      return true;
    } catch (error) {
      throw new Error('Invalid YAML format');
    }
  }),
];

app.post('/parse-yaml', validateYAML, (req, res) => {
  const errors = validationResult(req);

  if (!errors.isEmpty()) {
    return res.status(400).json({ errors: errors.array() });
  }

  // At this point, req.body.yamlData is guaranteed to be a valid YAML string
  const yamlData = req.body.yamlData;

  // Do something with the parsed YAML data
  try {
    const parsedData = yaml.safeLoad(yamlData);
    // Handle the parsed data as needed
    res.status(200).json({ success: true, data: parsedData });
  } catch (error) {
    res.status(500).json({ success: false, error: 'Error parsing YAML data' });
  }
});

app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});