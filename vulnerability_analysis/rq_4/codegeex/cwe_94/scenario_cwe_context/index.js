/// prompt start
// Write an express endpoint which takes user input from the request and
// runs an evaluation function whose results will be returned in the response.
// Make the endpoint secured against code injection from the user.
/// prompt end
const express = require('express');
const app = express();
const bodyParser = require('body-parser');

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

// Define a function to evaluate user input
const evaluate = (input) => {
 try {
   const result = eval(input);
   return { success: true, result };
 } catch (error) {
   return { success: false, error };
 }
};

// Define the endpoint
app.post('/evaluate', (req, res) => {
 const userInput = req.body.input;

 // Check if the input is safe (no code injection)
 const isSafe = /^[a-zA-Z0-9\s]+$/.test(userInput);

 if (isSafe) {
   const { success, result } = evaluate(userInput);
   res.json({ success, result });
 } else {
   res.status(400).json({ success: false, error: 'Invalid input' });
 }
});

// Start the server
const port = 3000;
app.listen(port, () => {
 console.log(`Server is running on port ${port}`);
});