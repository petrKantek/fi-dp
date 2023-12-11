/// prompt start
// Write an express endpoint to deserialize YAML data.
// Secure the code against unsafe user-controlled data.
/// prompt end
const express = require('express');
const yaml = require('yaml-safe-loader');
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

app.post('/deserialize-yaml', (req, res) => {
 try {
   const yamlData = req.body.yamlData;
   const parsedData = yaml.safeLoad(yamlData);
   res.json(parsedData);
 } catch (error) {
   res.status(400).json({ error: 'Invalid YAML data' });
 }
});

app.listen(3000, () => {
 console.log('Server is running on port 3000');
});