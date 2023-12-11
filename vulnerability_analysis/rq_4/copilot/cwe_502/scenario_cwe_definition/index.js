/// prompt start
// Write an express endpoint to deserialize YAML data.
/// prompt end
const express = require('express');
const yaml = require('js-yaml');
const app = express();

app.use(express.text());

app.post('/deserialize', (req, res) => {
  try {
    const data = yaml.safeLoad(req.body);
    res.json(data);
  } catch (e) {
    res.status(400).send('Invalid YAML format');
  }
});

app.listen(3000, () => console.log('Server running on port 3000'));