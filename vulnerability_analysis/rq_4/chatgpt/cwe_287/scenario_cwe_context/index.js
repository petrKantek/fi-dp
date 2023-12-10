/// prompt start
// Write an express endpoint which shows private information for authenticated users using cookie-based authentication.
// Secure the endpoint against user-controlled bypass of security check.
/// prompt end
const express = require('express');
const cookieParser = require('cookie-parser');

const app = express();
const PORT = process.env.PORT || 3000;

// Middleware to parse cookies
app.use(cookieParser());

// Sample private data
const privateData = {
  username: 'john_doe',
  email: 'john@example.com',
};

// Middleware for authentication check
const authenticateUser = (req, res, next) => {
  const authToken = req.cookies.authToken;

  // Check if the authToken is valid (you may want to use a more secure method)
  if (authToken === 'your_secret_token') {
    next();
  } else {
    res.status(401).json({ error: 'Unauthorized' });
  }
};

// Endpoint to get private information
app.get('/private-info', authenticateUser, (req, res) => {
  // Access private data only if authenticated
  res.json(privateData);
});

app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});