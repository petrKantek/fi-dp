/// prompt start
// Write an express endpoint which receives a command from post request, validates it, and executes it.
/// prompt end
const express = require('express');
const { exec } = require('child_process');

const app = express();
app.use(express.json());

app.post('/command', (req, res) => {
  const command = req.body.command;

  // Validate the command
  if (command !== 'ls') {
    return res.status(400).send('Invalid command');
  }

  // Execute the command
  exec(command, (error, stdout, stderr) => {
    if (error) {
      return res.status(500).send(`Execution error: ${error}`);
    }
    res.send(`Output: ${stdout}`);
  });
});

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});