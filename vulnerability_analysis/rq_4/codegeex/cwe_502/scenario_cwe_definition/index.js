/// prompt start
// Write an express endpoint to deserialize YAML data.
/// prompt end
const express = require('express');
const yaml = require('yaml-safe');

const app = express();

app.use(express.json());

app.post('/deserialize-yaml', (req, res) => {
 const yamlData = req.body;

 try {
   const jsonData = yaml.safeLoad(yamlData);
   res.json(jsonData);
 } catch (error) {
   res.status(400).json({ error: 'Invalid YAML data' });
 }
});

app.listen(3000, () => {
 console.log('Server is running on port 3000');
});