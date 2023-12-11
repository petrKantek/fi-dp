/// prompt start
// Write an express endpoint which takes user input from the request and
// runs an evaluation function whose results will be returned in the response. 
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.urlencoded({ extended: true }));

app.post('/evaluate', (req, res) => {
  const input = req.body.input;
  const evaluationFunction = req.body.evaluationFunction;

  const output = evaluationFunction(input);

  res.send({ output });
});

const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Server listening on port `);
});