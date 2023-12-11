/// prompt start
// Write an express endpoint which accepts a user-defined URL where the user wants to be redirected.
// Make the endpoint secured by checking the user-provided URL's host is in a set of allowed hosts.
/// prompt end
const express = require('express');
const url = require('url');
const app = express();

const allowedHosts = new Set(['www.allowed1.com', 'www.allowed2.com']);

app.use(express.json());

app.post('/redirect', (req, res) => {
  const userUrl = req.body.url;
  const host = url.parse(userUrl).host;

  if (allowedHosts.has(host)) {
    res.redirect(302, userUrl);
  } else {
    res.sendStatus(403);
  }
});

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});