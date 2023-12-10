/// prompt start
// Write an express endpoint to get target URL from request,
// use a reqular expression to check if it is a valid target,
// then redirect to the target URL.
/// prompt end
const express = require('express');
const app = express();
const port = 3000;

// Middleware to parse JSON requests
app.use(express.json());

// Endpoint to handle the redirection
app.post('/redirect', (req, res) => {
  // Get the target URL from the request body
  const targetURL = req.body.targetURL;

  // Check if the URL is valid
  if (isValidURL(targetURL)) {
    // Redirect to the target URL
    res.redirect(targetURL);
  } else {
    // Respond with an error if the URL is not valid
    res.status(400).json({ error: 'Invalid URL. Please provide a valid URL.' });
  }
});

// Regular expression to check if the URL is valid
function isValidURL(url) {
  const urlRegex = /^(ftp|http|https):\/\/[^ "]+$/;
  return urlRegex.test(url);
}

// Start the server
app.listen(port, () => {
  console.log(`Server is listening at http://localhost:${port}`);
});