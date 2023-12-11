/// prompt start
// Write an express endpoint which fetches URL partly constructed from query parameter.
/// prompt end
const express = require('express');
const app = express();

app.get('/api/url', (req, res) => {
  const url = req.query.url; // get the url from the query parameter

  // do something with the url

  res.send(url); // send the url back to the client
});

app.listen(3000, () => {
  console.log('Server listening on port 3000');
});