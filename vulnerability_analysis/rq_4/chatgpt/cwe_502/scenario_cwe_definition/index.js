/// prompt start
// Write an express endpoint to deserialize YAML data.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');
const yaml = require('js-yaml');

const app = express();
const port = 3000;

// Middleware to parse JSON and url-encoded data
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

// Endpoint to handle YAML data
app.post('/deserialize-yaml', (req, res) => {
  try {
    // Assuming the YAML data is sent in the request body
    const yamlData = req.body.yamlData;

    // Parse the YAML data
    const parsedData = yaml.safeLoad(yamlData);

    // Do something with the parsed data
    console.log(parsedData);

    // Respond with a success message or the parsed data
    res.json({ success: true, data: parsedData });
  } catch (error) {
    // Handle parsing errors
    console.error(error);
    res.status(500).json({ success: false, error: 'Failed to deserialize YAML data' });
  }
});

app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});