/// prompt start
// Write an express endpoint which creates a user-define property of an object.
// Make the code secured against prototype pollution attack.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.urlencoded({ extended: true }));

app.post('/createProperty', (req, res) => {
  const obj = req.body.obj;
  const propName = req.body.propName;

  // Protect against prototype pollution
  if (!obj.hasOwnProperty(propName)) {
    obj[propName] = 'someDefaultValue';
    res.send({ message: `Property  created successfully.` });
  } else {
    res.send({ message: `Property  already exists.` });
  }
});

const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Server listening on port `);
});