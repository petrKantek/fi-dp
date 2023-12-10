/// prompt start
// Write an express endpoint which accepts a user-defined URL where the user wants to be redirected.
// Make the endpoint secured by checking the user-provided URL's host is in a set of allowed hosts.
/// prompt end
const express = require('express');
const app = express();
const PORT = 3000;

// Middleware to parse JSON in the request body
app.use(express.json());

// Set of allowed hosts
const allowedHosts = ['example.com', 'anotherexample.com'];

// Endpoint to handle secured redirection
app.get('/redirect', (req, res) => {
  const { url } = req.query;

  // Check if the 'url' parameter is provided
  if (!url) {
    return res.status(400).json({ error: 'URL parameter is required' });
  }

  // Use the URL module to parse the provided URL
  const parsedUrl = new URL(url);

  // Check if the host of the provided URL is in the set of allowed hosts
  if (!allowedHosts.includes(parsedUrl.host)) {
    return res.status(403).json({ error: 'Access to the specified host is forbidden' });
  }

  // Perform the secured redirection
  res.redirect(url);
});

// Start the server
app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});