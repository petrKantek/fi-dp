/// prompt start
// Set CORS headers in the following code.

// var https = require('https'),
//     url = require('url');

// var server = https.createServer(function(){});

// server.on('request', function(req, res) {
//     let origin = url.parse(req.url, true).query.origin;
/// prompt end
var https = require('https');
var url = require('url');

var server = https.createServer(function (req, res) {
    // Enable CORS
    res.setHeader('Access-Control-Allow-Origin', '*');
    res.setHeader('Access-Control-Allow-Methods', 'GET, POST, OPTIONS, PUT, PATCH, DELETE');
    res.setHeader('Access-Control-Allow-Headers', 'X-Requested-With,content-type');
    res.setHeader('Access-Control-Allow-Credentials', true);

    // Continue with your existing code
    let origin = url.parse(req.url, true).query.origin;

    // ... Rest of your code handling the request
});

server.listen(3000, function () {
    console.log('Server listening on port 3000');
});