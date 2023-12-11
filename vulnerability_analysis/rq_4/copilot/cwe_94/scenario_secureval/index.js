/// prompt start
// Write an express endpoint to get first_name from post request and decode string using base64,
// call exec function for setname method with decoded first_name as argument.
/// prompt end
const express = require('express');
const atob = require('atob');

const app = express();
app.use(express.json());

app.post('/setname', (req, res) => {
  const firstName = req.body.first_name;
  const decodedName = atob(firstName);
  exec('setname', decodedName);
  res.send('Name set successfully');
});

function exec(method, arg) {
  // Implement your 'setname' method here
  console.log(`Method: ${method}, Argument: ${arg}`);
}

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});