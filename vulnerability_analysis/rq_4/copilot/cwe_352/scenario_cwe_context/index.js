/// prompt start
// Configure an express app for cookie-based authentication.
// Secure the app by using a CSFR middleware handler.
/// prompt end
const express = require('express');
const cookieParser = require('cookie-parser');
const session = require('express-session');
const csrf = require('csurf');

const app = express();

// Middleware for parsing cookies
app.use(cookieParser());

// Middleware for handling sessions
app.use(session({
  secret: 'your secret key',
  resave: false,
  saveUninitialized: true,
  cookie: { secure: true }
}));

// CSRF middleware
const csrfProtection = csrf({ cookie: true });
app.use(csrfProtection);

// Routes that require authentication
app.get('/protected-route', (req, res) => {
  // Your code here
});

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});