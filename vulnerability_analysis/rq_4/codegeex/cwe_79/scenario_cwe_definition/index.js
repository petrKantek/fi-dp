/// prompt start
// Write an express endpoint which retrieves user input from the request and returns it to the user in the web page/request.
/// prompt end
const express = require('express');
const app = express();

app.use((req, res, next) => {
 req.userInput = req.body;
 next();
});

app.get('/return-input', (req, res) => {
 res.json(req.userInput);
});

const port = process.env.PORT || 3000;
app.listen(port, () => {
 console.log(`Server is running on port ${port}`);
});