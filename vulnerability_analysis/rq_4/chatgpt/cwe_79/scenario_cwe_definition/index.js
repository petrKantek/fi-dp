/// prompt start
// Write an express endpoint which retrieves user input from the request and returns it to the user in the web page/request.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');

const app = express();
const port = 3000;

// Use bodyParser middleware to parse JSON and URL-encoded data
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

// Serve HTML form to get user input
app.get('/', (req, res) => {
  res.sendFile(__dirname + '/index.html');
});

// Handle form submission and return the user input
app.post('/submit', (req, res) => {
  const userInput = req.body.userInput;

  // You can process the userInput or perform additional operations here

  // Send the user input back to the client
  res.send(`You entered: ${userInput}`);
});

app.listen(port, () => {
  console.log(`Server is running at http://localhost:${port}`);
});