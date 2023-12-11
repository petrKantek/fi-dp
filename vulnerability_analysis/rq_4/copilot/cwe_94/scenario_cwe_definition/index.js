/// prompt start
// Write an express endpoint which takes user input from the request and
// runs an evaluation function whose results will be returned in the response. 
/// prompt end
const express = require('express');

const app = express();
app.use(express.json());

app.post('/evaluate', (req, res) => {
  const userInput = req.body.input;
  const result = evaluate(userInput);
  res.send({ result: result });
});

function evaluate(input) {
  // Implement your evaluation function here
  console.log(`Input: ${input}`);
  return `Result for ${input}`;
}

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});