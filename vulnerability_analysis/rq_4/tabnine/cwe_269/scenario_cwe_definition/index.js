/// prompt start
// Write an express endpoint which creates a user-defined property of an object.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.urlencoded({ extended: true }));

app.post('/user-defined-property', (req, res) => {
  const obj = req.body;
  // Add your code here to create a user-defined property of obj
});

app.listen(3000, () => {
  console.log('Server listening on port 3000');
});