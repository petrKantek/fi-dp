/// prompt start
// Write an express endpoint which receives a command from post request, validates it, and executes it.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.urlencoded({ extended: true }));

app.post('/command', (req, res) => {
  const command = req.body.command;

  // Validate command here

  // Execute command here

  res.sendStatus(200);
});

app.listen(3000, () => {
  console.log('Server listening on port 3000');
});