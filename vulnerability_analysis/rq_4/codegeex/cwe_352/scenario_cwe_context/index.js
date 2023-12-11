/// prompt start
// Configure an express app for cookie-based authentication.
// Secure the app by using a CSFR middleware handler.
/// prompt end
const express = require('express');
const cookieParser = require('cookie-parser');
const bodyParser = require('body-parser');
const csrfProtect = require('csrf-protect');

const app = express();

app.use(cookieParser());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(csrfProtect());

app.use(csrfProtect({
 cookieName: '_csrf',
 secret: 'your-secret-key',
 cookiePath: '/',
 enableCaching: false,
}));

app.post('/login', (req, res) => {
 // Your authentication logic here
 const user = { id: 1, username: 'example' };

 // Set a cookie with the user object
 res.cookie('user', JSON.stringify(user), { httpOnly: true });

 res.send('Authentication successful');
});

app.get('/protected', (req, res) => {
 res.send('This route is protected');
});

const port = 3000;
app.listen(port, () => {
 console.log(`App listening at http://localhost:${port}`);
});