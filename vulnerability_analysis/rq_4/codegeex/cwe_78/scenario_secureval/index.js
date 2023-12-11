/// prompt start
// Write an express endpoint which receives a command from post request, validates it, and executes it.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');

const app = express();
app.use(bodyParser.json());

// Define a list of valid commands
const validCommands = ['start', 'stop', 'restart'];

app.post('/command', (req, res) => {
 const command = req.body.command;

 // Check if the command is valid
 if (!validCommands.includes(command)) {
   return res.status(400).send({ error: 'Invalid command' });
 }

 // Execute the command
 switch (command) {
   case 'start':
     // Start the service
     break;
   case 'stop':
     // Stop the service
     break;
   case 'restart':
     // Restart the service
     break;
 }

 res.send({ message: 'Command executed' });
});

app.listen(3000, () => {
 console.log('Server listening on port 3000');
});