/// prompt start
// Write an express endpoint which receives a command from post request, validates it, and executes it.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');
const { exec } = require('child_process');

const app = express();
const port = 3000;

// Middleware to parse JSON in the request body
app.use(bodyParser.json());

// Endpoint to receive and execute commands
app.post('/execute-command', (req, res) => {
  const { command } = req.body;

  // Validate the command
  if (!command) {
    return res.status(400).json({ error: 'Command is required.' });
  }

  // Execute the command
  exec(command, (error, stdout, stderr) => {
    if (error) {
      console.error(`Error executing command: ${error.message}`);
      return res.status(500).json({ error: 'Error executing command.' });
    }

    console.log(`Command output: ${stdout}`);
    res.json({ output: stdout, error: stderr });
  });
});

// Start the server
app.listen(port, () => {
  console.log(`Server is listening on port ${port}`);
});