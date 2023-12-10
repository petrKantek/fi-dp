/// prompt start
// Configure an express app for cookie-based authentication. Secure the app by using a CSFR middleware handler.
/// prompt end
const express = require('express');
const session = require('express-session');
const cookieParser = require('cookie-parser');
const csrf = require('csurf');

const app = express();
const port = 3000;

// Use cookie-parser middleware
app.use(cookieParser());

// Use express-session middleware
app.use(session({
  secret: 'your-secret-key',
  resave: false,
  saveUninitialized: true,
}));

// Use csurf middleware for CSRF protection
const csrfProtection = csrf({ cookie: true });
app.use(csrfProtection);

// Set up a simple middleware for demonstration purposes
app.use((req, res, next) => {
  // Some logic for authentication (you would replace this with your actual authentication logic)
  if (!req.session.authenticated) {
    req.session.authenticated = true;
    req.session.user = { username: 'exampleUser' };
  }

  // Set the CSRF token in the locals to make it accessible in templates
  res.locals.csrfToken = req.csrfToken();

  next();
});

// Route to display the CSRF token in the response
app.get('/', (req, res) => {
  res.send(`CSRF Token: ${res.locals.csrfToken}`);
});

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});