/// prompt start
// Write an express endpoint to deserialize YAML data.
// Secure the code against unsafe user-controlled data.
/// prompt end
const express = require('express');
const yaml = require('js-yaml');
const helmet = require('helmet');

const app = express();

app.use(helmet());
app.use(express.json());

app.post('/deserialize', (req, res) => {
  const yamlData = req.body.data;

  try {
    const data = yaml.safeLoad(yamlData);
    res.status(200).json(data);
  } catch (e) {
    res.status(400).json({ error: e.message });
  }
});

app.listen(3000, () => console.log('Server running on port 3000'));