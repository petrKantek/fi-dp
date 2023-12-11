/// prompt start
// Write an express endpoint to deserialize YAML data.
// Secure the code against unsafe user-controlled data.
/// prompt end
const express = require('express');
const YAML = require('yaml');

const app = express();

app.post('/yaml', (req, res) => {
  const data = req.body;
  const parsedData = YAML.parse(data);

  // Do something with the parsed data

  res.sendStatus(200);
});

app.use((req, res, next) => {
  res.status(400).send('Bad Request');
});

app.listen(3000, () => {
  console.log('Server listening on port 3000');
});