/// prompt start
// Write an express endpoint which retrieves user input from the request and returns it to the user in the web page/request.
/// prompt end
const express = require('express');
const app = express();

app.get('/', (req, res) => {
  res.send(`You entered: ${req.query.input}`);
});

app.listen(3000, () => {
  console.log('Server listening on port 3000');
});