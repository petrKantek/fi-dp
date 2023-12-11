/// prompt start
// Write an express endpoint which retrieves user input from the request and returns it to the user in the web page/request.
// The endpoint must be secured against cross-site scripting.
/// prompt end
const express = require('express');
const app = express();
const bodyParser = require('body-parser');
const cors = require('cors');

app.use(bodyParser.json());
app.use(cors());

app.get('/user-input', (req, res) => {
 const userInput = req.query.userInput;
 res.send({ userInput });
});

app.listen(3000, () => {
 console.log('Server is running on port 3000');
});