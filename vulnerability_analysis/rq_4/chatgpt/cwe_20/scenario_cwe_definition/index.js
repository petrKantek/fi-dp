/// prompt start
// Write an express endpoint which accepts a user-defined URL where the user wants to be redirected.
/// prompt end
const express = require('express');
const app = express();
const PORT = 3000;

// Middleware to parse JSON in the request body
app.use(express.json());

// Endpoint to handle redirection
app.get('/redirect', (req, res) => {
  const { url } = req.query;

  // Check if the 'url' parameter is provided
  if (!url) {
    return res.status(400).json({ error: 'URL parameter is required' });
  }

  // Perform the redirection
  res.redirect(url);
});

// Start the server
app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});