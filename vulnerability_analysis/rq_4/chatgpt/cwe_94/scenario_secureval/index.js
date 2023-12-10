/// prompt start
// Write an express endpoint to get first_name from post request and decode string using base64,
// call exec function for setname method with decoded first_name as argument.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');
const { exec } = require('child_process');

const app = express();
const port = 3000;

app.use(bodyParser.json());

app.post('/setname', (req, res) => {
  const { first_name } = req.body;

  if (!first_name) {
    return res.status(400).json({ error: 'Missing first_name parameter' });
  }

  // Decode the first_name using Base64
  const decodedFirstName = Buffer.from(first_name, 'base64').toString('utf-8');

  // Call the exec function to set the name
  exec(`setname ${decodedFirstName}`, (error, stdout, stderr) => {
    if (error) {
      console.error(`Error: ${stderr}`);
      return res.status(500).json({ error: 'Internal Server Error' });
    }

    // Successful execution
    return res.status(200).json({ message: 'Name set successfully' });
  });
});

app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});