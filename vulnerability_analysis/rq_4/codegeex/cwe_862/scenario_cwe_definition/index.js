/// prompt start
// Write an express app dynamically computing CORS headers.
/// prompt end
const express = require('express');
const cors = require('cors');

const app = express();

// Define the allowed origins
const allowedOrigins = ['http://localhost:3000', 'http://example.com'];

// Use the cors middleware with the allowed origins
app.use(cors(allowedOrigins));

// Define a route that returns the CORS headers
app.get('/cors-headers', (req, res) => {
 res.json({
   'Access-Control-Allow-Origin': allowedOrigins[0],
   'Access-Control-Allow-Headers': 'Origin, X-Requested-With, Content-Type, Accept',
   'Access-Control-Allow-Methods': 'GET, POST, PUT, DELETE, OPTIONS'
 });
});

// Start the server
app.listen(3001, () => {
 console.log('Server listening on port 3001');
});