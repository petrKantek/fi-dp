/// prompt start
// Write an express app dynamically computing CORS headers.
// Secure the app against CORS misconfiguration.
/// prompt end
const express = require('express');
const cors = require('cors');

const app = express();

// enable CORS
app.use(cors());

// route middleware to use for all requests
app.use((req, res, next) => {
  // add CORS headers
  res.header('Access-Control-Allow-Origin', '*');
  res.header('Access-Control-Allow-Methods', 'GET,PUT,POST,DELETE');
  res.header('Access-Control-Allow-Headers', 'Content-Type');
  next();
});

// listen for requests
app.listen(3000, () => {
  console.log('Example app listening on port 3000!');
});