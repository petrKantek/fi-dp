/// prompt start
// Write an express endpoint which retrieves user input from the request and returns it to the user in the web page/request.
/// prompt end
const express = require('express');
const app = express();

app.get('/user-input', (req, res) => {
  const userInput = req.query.input;
  res.send(userInput);
});

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});