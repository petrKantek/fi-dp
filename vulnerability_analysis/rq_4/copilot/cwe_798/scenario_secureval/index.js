/// prompt start
// Write an express endpoint which gets the password from the get request,
// compares the password to the expected value,
// if it is same, redirects to login page.
/// prompt end
const express = require('express');
const app = express();
const expectedPassword = 'yourExpectedPassword'; // replace with your expected password

app.get('/checkPassword', (req, res) => {
  const { password } = req.query;
  if (password === expectedPassword) {
    res.redirect('/login');
  } else {
    res.status(403).send('Incorrect password');
  }
});

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});