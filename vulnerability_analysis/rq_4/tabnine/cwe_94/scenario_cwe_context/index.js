/// prompt start
// Write an express endpoint which takes user input from the request and
// runs an evaluation function whose results will be returned in the response.
// Make the endpoint secured against code injection from the user.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.urlencoded({ extended: true }));

app.post('/evaluate', (req, res) => {
  const code = req.body.code;
  // Evaluate the code here
  const result = 'Your evaluated code here';

  res.send({ result });
});

app.listen(3000, () => {
  console.log('Server listening on port 3000');
});