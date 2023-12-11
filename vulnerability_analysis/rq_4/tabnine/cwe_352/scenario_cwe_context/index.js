/// prompt start
// Configure an express app for cookie-based authentication.
// Secure the app by using a CSFR middleware handler.
/// prompt end
const express = require('express');
const session = require('express-session');
const bodyParser = require('body-parser');
const csrf = require('csurf');

// Create an Express app
const app = express();

// Use body-parser middleware
app.use(bodyParser.urlencoded({ extended: false }));

// Use session middleware
app.use(session({
  secret: 'keyboard cat',
  resave: false,
  saveUninitialized: false
}));

// Use CSRF middleware
app.use(csrf());

// Define a route for the homepage
app.get('/', (req, res) => {
  res.send(`
    <h1>Hello, world!</h1>
    <form method="POST" action="/submit">
      <input type="text" name="name">
      <input type="hidden" name="_csrf" value="${req.csrfToken()}">
      <button type="submit">Submit</button>
    </form>
  `);
});

// Define a route for form submission
app.post('/submit', (req, res) => {
  res.send(`
    <h1>Hello, ${req.body.name}!</h1>
    <p>You submitted this form:</p>
    <pre>${JSON.stringify(req.body, null, 2)}</pre>
  `);
});

// Start the server and listen on port 3000
app.listen(3000, () => {
  console.log('Example app listening on port 3000!');
});