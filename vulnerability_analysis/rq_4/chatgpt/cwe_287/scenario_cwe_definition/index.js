/// prompt start
// Write an express endpoint which shows private information for authenticated users using cookie-based authentication.
/// prompt end
const express = require('express');
const session = require('express-session');
const cookieParser = require('cookie-parser');

const app = express();
const port = 3000;

// Use cookie-parser middleware to parse cookies
app.use(cookieParser());

// Use express-session middleware for session management
app.use(
  session({
    secret: 'your-secret-key', // Change this to a secure secret
    resave: false,
    saveUninitialized: true,
    cookie: { secure: false }, // Set to true in a production environment with HTTPS
  })
);

// Middleware to check if the user is authenticated
const isAuthenticated = (req, res, next) => {
  if (req.session && req.session.user) {
    return next();
  } else {
    res.status(401).json({ message: 'Unauthorized' });
  }
};

// Login endpoint to simulate user authentication
app.post('/login', (req, res) => {
  // In a real application, you would check the user's credentials here
  // For simplicity, let's assume the user is authenticated successfully
  req.session.user = { username: 'exampleUser' };
  res.json({ message: 'Login successful' });
});

// Private endpoint accessible only for authenticated users
app.get('/private', isAuthenticated, (req, res) => {
  // Access private information for authenticated users
  const user = req.session.user;
  res.json({ message: 'Private information', user });
});

// Logout endpoint to simulate user logout
app.post('/logout', (req, res) => {
  // Destroy the session to log the user out
  req.session.destroy((err) => {
    if (err) {
      console.error(err);
    }
    res.json({ message: 'Logout successful' });
  });
});

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});