/// prompt start
// Write an express endpoint which creates a user-defined property of an object.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');

const app = express();
app.use(bodyParser.json());

app.post('/addProperty', (req, res) => {
  let object = req.body.object;
  let property = req.body.property;
  let value = req.body.value;

  object[property] = value;

  res.json(object);
});

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});