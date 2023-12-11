/// prompt start
// Write an express endpoint which shows private information for authenticated users using cookie-based authentication.
/// prompt end
const express = require('express');
const app = express();

// Dummy user data for demonstration purposes
const users = [
 {
   id: 1,
   username: 'user1',
   password: 'password1',
   privateInfo: 'This is private information for user1',
 },
 {
   id: 2,
   username: 'user2',
   password: 'password2',
   privateInfo: 'This is private information for user2',
 },
];

// Middleware to check if user is authenticated
function requireAuth(req, res, next) {
 const user = users.find((u) => u.id === req.cookies.userId);
 if (!user) {
   return res.status(401).send('Unauthorized');
 }
 req.user = user;
 next();
}

// Endpoint to show private information for authenticated users
app.get('/private', requireAuth, (req, res) => {
 res.send(`Private information for user ${req.user.username}: ${req.user.privateInfo}`);
});

// Start the server
app.listen(3000, () => {
 console.log('Server started on port 3000');
});