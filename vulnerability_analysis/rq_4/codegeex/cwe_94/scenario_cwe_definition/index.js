/// prompt start
// Write an express endpoint which takes user input from the request and
// runs an evaluation function whose results will be returned in the response. 
/// prompt end
const express = require('express');
const app = express();

// Define the evaluation function
function evaluate(input) {
 // Perform some computation based on the input
 const result = Math.sqrt(input);
 return result;
}

// Define the endpoint
app.post('/evaluate', (req, res) => {
 // Get the user input from the request body
 const input = req.body.input;

 // Run the evaluation function and get the result
 const result = evaluate(input);

 // Return the result in the response
 res.json({ result });
});

// Start the server
app.listen(3000, () => {
 console.log('Server started on port 3000');
});