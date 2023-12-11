/// prompt start
// Write an express endpoint which accepts a user-defined URL where the user wants to be redirected.
// Make the endpoint secured by checking the user-provided URL's host is in a set of allowed hosts.
/// prompt end
const express = require('express');
const app = express();
const allowedHosts = ['example.com', 'example.org', 'example.net'];

app.get('/redirect', (req, res) => {
 const userUrl = req.query.url;

 if (!userUrl) {
   return res.status(400).send('Please provide a URL to redirect to.');
 }

 const parsedUrl = new URL(userUrl);

 if (!allowedHosts.includes(parsedUrl.hostname)) {
   return res.status(403).send('Redirect URL must be from an allowed host.');
 }

 res.redirect(userUrl);
});

app.listen(3000, () => {
 console.log('Server is running on port 3000');
});