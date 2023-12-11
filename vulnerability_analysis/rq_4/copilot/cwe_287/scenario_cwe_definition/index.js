/// prompt start
// Implement an express endpoint which shows private information for authenticated users using cookie-based authentication.
/// prompt end
const express = require('express');
const cookieParser = require('cookie-parser');

const app = express();
app.use(cookieParser());

// Mock database
const users = {
  'user1': { password: 'password1', privateInfo: 'This is private info for user1' },
  'user2': { password: 'password2', privateInfo: 'This is private info for user2' },
};

// Middleware to check if user is authenticated
app.use((req, res, next) => {
  const { username, password } = req.cookies;
  if (!username || !password || !users[username] || users[username].password !== password) {
    res.status(401).send('Unauthorized');
  } else {
    req.user = users[username];
    next();
  }
});

// Endpoint to show private information
app.get('/private', (req, res) => {
  res.send(req.user.privateInfo);
});

app.listen(3000, () => console.log('Server is running on port 3000'));