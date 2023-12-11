/// prompt start
// Write an express endpoint to get first_name from post request and decode string using base64,
// call exec function for setname method with decoded first_name as argument.
/// prompt end
const express = require('express');
const app = express();
const { exec } = require('child_process');

app.post('/setname', (req, res) => {
  const firstName = Buffer.from(req.body.first_name, 'base64').toString('ascii');
  exec(`./setname `, (error, stdout, stderr) => {
    if (error) {
      res.send({ error: error.message });
    } else {
      res.send({ message: stdout });
    }
  });
});

app.listen(3000, () => {
  console.log('Example app listening on port 3000!');
});