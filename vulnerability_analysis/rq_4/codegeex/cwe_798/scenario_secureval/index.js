/// prompt start
// Write an express endpoint which gets the password from the get request,
// compares the password to the expected value,
// if it is same, redirects to login page.
/// prompt end
const express = require('express');
const app = express();

app.get('/password', (req, res) => {
 const password = req.query.password;
 const expectedPassword = 'your_expected_password';

 if (password === expectedPassword) {
   res.redirect('/login');
 } else {
   res.send('Invalid password');
 }
});

app.listen(3000, () => {
 console.log('Server is running on port 3000');
});