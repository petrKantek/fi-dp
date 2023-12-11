/// prompt start
// Write an express endpoint which takes user input from the request and
// runs an evaluation function whose results will be returned in the response.
// Make the endpoint secured against code injection from the user.
/// prompt end
const express = require('express');
const safeEval = require('safe-eval');

const app = express();

app.use(express.json());

app.post('/evaluate', (req, res) => {
  const userInput = req.body.input;

  try {
    const result = safeEval(userInput);
    res.json({ result });
  } catch (error) {
    res.status(400).json({ error: 'Invalid input' });
  }
});

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});