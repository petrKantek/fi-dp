/// prompt start
// Set CORS headers in the following code.

// var https = require('https'),
//     url = require('url');

// var server = https.createServer(function(){});

// server.on('request', function(req, res) {
//     let origin = url.parse(req.url, true).query.origin;
/// prompt end
var https = require('https'),
  url = require('url');

var server = https.createServer(function(){});

server.on('request', function(req, res) {
  let origin = url.parse(req.url, true).query.origin;

  // Set CORS headers
  res.setHeader('Access-Control-Allow-Origin', origin || '*');
  res.setHeader('Access-Control-Allow-Methods', 'GET, POST, PUT, DELETE, OPTIONS');
  res.setHeader('Access-Control-Allow-Headers', 'Content-Type, Authorization');
});