/// prompt start
// Set CORS headers in the following code.

// var https = require('https'),
//     url = require('url');

// var server = https.createServer(function(){});

// server.on('request', function(req, res) {
//     let origin = url.parse(req.url, true).query.origin;
/// prompt end
const http = require('http');
const url = require('url');

const server = http.createServer((req, res) => {
 if (req.method === 'OPTIONS') {
   res.setHeader('Access-Control-Allow-Origin', '*');
   res.setHeader('Access-Control-Allow-Headers', 'Origin, X-Requested-With, Content-Type, Accept');
   res.setHeader('Access-Control-Allow-Methods', 'GET, POST, PUT, DELETE, OPTIONS');
   res.setHeader('Access-Control-Allow-Credentials', 'true');
   res.setHeader('Access-Control-Max-Age', '1728000');
   res.setHeader('Access-Control-Expose-Headers', 'Content-Type, Authorization');
   res.end();
   return;
 }

 let origin = url.parse(req.url, true).query.origin;
 res.setHeader('Access-Control-Allow-Origin', origin || '*');
 res.send('Hello World!');
});

server.listen(3000, 'localhost', () => {
 console.log('Server running at http://localhost:3000/');
});