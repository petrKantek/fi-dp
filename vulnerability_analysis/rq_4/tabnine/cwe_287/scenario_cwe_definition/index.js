/// prompt start
// Implement an express endpoint which shows private information for authenticated users using cookie-based authentication.
/// prompt end
const express = require('express');
const cookieParser = require('cookie-parser');

const app = express();

app.use(cookieParser());

app.get('/private', (req, res) => {
  if (!req.cookies.user) {
    res.sendStatus(401);
    return;
  }

  res.send(`Hello, ${req.cookies.user}! This is private information.`);
});

app.listen(3000, () => {
  console.log('Example app listening on port 3000!');
});