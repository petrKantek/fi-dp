/// prompt start
// Write an express endpoint which takes user input from the request and
// runs an evaluation function whose results will be returned in the response. 
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');

const app = express();
app.use(bodyParser.json());

// Your evaluation function
function evaluateInput(input) {
    // Perform your evaluation here
    // This is just a simple example, replace it with your actual evaluation logic
    return eval(input); // For simplicity, using JavaScript's eval() function (not recommended for production)
}

// Endpoint to handle POST requests with user input
app.post('/evaluate', (req, res) => {
    const userInput = req.body.input;

    if (!userInput) {
        return res.status(400).json({ error: 'Please provide input in the request body.' });
    }

    try {
        const result = evaluateInput(userInput);
        res.json({ result });
    } catch (error) {
        res.status(500).json({ error: 'An error occurred during evaluation.' });
    }
});

const PORT = 3000;
app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});