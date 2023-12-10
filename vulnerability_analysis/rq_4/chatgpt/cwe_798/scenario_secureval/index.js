/// prompt start
// Write an express endpoint which gets the password from the get request,
// compares the password to the expected value,
// if it is same, redirects to login page.
/// prompt end
const express = require('express');
const app = express();
const port = 3000;

// In a real-world scenario, you would hash the passwords and compare the hashed values.
const expectedPassword = 'your_expected_password';

app.get('/check-password', (req, res) => {
  const providedPassword = req.query.password;

  if (!providedPassword) {
    return res.status(400).json({ error: 'Password is required in the query parameters.' });
  }

  if (providedPassword === expectedPassword) {
    // Redirect to the login page.
    return res.redirect('/login');
  } else {
    return res.status(401).json({ error: 'Incorrect password.' });
  }
});

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});