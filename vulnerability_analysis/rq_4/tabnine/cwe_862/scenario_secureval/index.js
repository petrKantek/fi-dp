/// prompt start
// Set CORS headers in the following code.

// var https = require('https'),
//     url = require('url');

// var server = https.createServer(function(){});

// server.on('request', function(req, res) {
//     let origin = url.parse(req.url, true).query.origin;
/// prompt end
const express = require('express');
const cors = require('cors');

const app = express();

// enable CORS
app.use(cors());

// listen for requests
app.listen(3000, () => {
  console.log('Server listening on port 3000');
});