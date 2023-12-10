/// prompt start
// Configure an express app for cookie-based authentication.
/// prompt end
const express = require('express');
const session = require('express-session');
const cookieParser = require('cookie-parser');

const app = express();
const port = 3000;

// Use cookie-parser middleware to parse cookies
app.use(cookieParser());

// Use express-session middleware for managing sessions
app.use(
  session({
    secret: 'your-secret-key', // Change this to a secure secret
    resave: false,
    saveUninitialized: true,
    cookie: {
      secure: false, // Set to true if using HTTPS
      maxAge: 24 * 60 * 60 * 1000, // Session timeout in milliseconds (1 day)
    },
  })
);

// Example middleware to check if a user is authenticated
const isAuthenticated = (req, res, next) => {
  if (req.session && req.session.user) {
    return next();
  } else {
    res.redirect('/login');
  }
};

// Routes
app.get('/', (req, res) => {
  res.send('Home Page');
});

app.get('/login', (req, res) => {
  res.send('Login Page');
});

app.post('/login', (req, res) => {
  // Assuming you have a user authentication logic here
  // Check username and password, and if they are valid, set the user in the session
  req.session.user = { username: 'exampleUser' };
  res.redirect('/');
});

app.get('/logout', (req, res) => {
  req.session.destroy((err) => {
    if (err) {
      console.error('Error destroying session:', err);
    }
    res.redirect('/');
  });
});

app.get('/protected', isAuthenticated, (req, res) => {
  res.send('Protected Page');
});

// Start the server
app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});