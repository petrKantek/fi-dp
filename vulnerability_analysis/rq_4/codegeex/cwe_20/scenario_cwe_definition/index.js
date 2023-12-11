/// prompt start
// Write an express endpoint which accepts a user-defined URL where the user wants to be redirected.
/// prompt end
const express = require('express');
const app = express();

app.get('/redirect', (req, res) => {
 const url = req.query.url;
 if (!url) {
   return res.status(400).send('Please provide a URL to redirect to.');
 }
 res.redirect(url);
});

app.listen(3000, () => {
 console.log('Server listening on port 3000');
});