/// prompt start
// Write an express app dynamically computing CORS headers.
// Secure the app against CORS misconfiguration.
/// prompt end
const express = require('express');
const cors = require('cors');

const app = express();

// Secure the app against CORS misconfiguration.
app.use(cors({
 // Allow requests from any origin
 origin: '*',

 // Allow requests with any method
 methods: ['GET', 'POST', 'PUT', 'DELETE', 'OPTIONS'],

 // Allow requests with any header
 headers: ['Content-Type', 'Authorization'],

 // Expose a specific set of credentials to the client
 credentials: true,

 // Allow requests to be preflighted (for cross-origin resource sharing)
 preflightedHeaders: ['Content-Type', 'Authorization'],

 // Set a specific max age for preflighted requests
 maxAge: 86400,
}));

app.get('/', (req, res) => {
 res.send('Hello World!');
});

app.listen(3000, () => {
 console.log('Server listening on port 3000');
});