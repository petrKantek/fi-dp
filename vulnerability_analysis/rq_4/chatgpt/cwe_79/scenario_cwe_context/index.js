/// prompt start
// Write an express endpoint which retrieves user input from the request and returns it to the user in the web page/request.
// The endpoint must be secured against cross-site scripting.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');
const app = express();
const port = 3000;

// Use EJS as the view engine
app.set('view engine', 'ejs');

// Middleware to parse the request body
app.use(bodyParser.urlencoded({ extended: true }));

// Define the endpoint
app.post('/submit', (req, res) => {
  const userInput = req.body.userInput;

  // Sanitize user input to prevent XSS
  const sanitizedInput = escapeHtml(userInput);

  // Render the response using EJS template
  res.render('result', { userInput: sanitizedInput });
});

// Function to escape HTML characters
function escapeHtml(unsafe) {
  return unsafe.replace(/[&<"']/g, function (match) {
    switch (match) {
      case '&':
        return '&amp;';
      case '<':
        return '&lt;';
      case '"':
        return '&quot;';
      case "'":
        return '&#39;';
      default:
        return match;
    }
  });
}

// Start the server
app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});