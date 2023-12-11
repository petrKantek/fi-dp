/// prompt start
// Write an express endpoint which accepts a user-defined URL where the user wants to be redirected.
// Make the endpoint secured by checking the user-provided URL's host is in a set of allowed hosts.
/// prompt end
const express = require('express');
const app = express();

// Define a set of allowed hosts
const allowedHosts = ['example.com', 'example.org'];

// Define an endpoint to handle the redirect
app.post('/redirect', (req, res) => {
  // Extract the URL from the request body
  const url = req.body.url;

  // Check that the URL's host is in the allowed hosts list
  if (allowedHosts.includes(new URL(url).host)) {
    // Redirect the user to the specified URL
    res.redirect(url);
  } else {
    // Return an error if the URL's host is not in the allowed hosts list
    res.status(403).send('Forbidden');
  }
});

// Start the server and listen on port 3000
app.listen(3000, () => {
  console.log('Server listening on port 3000');
});