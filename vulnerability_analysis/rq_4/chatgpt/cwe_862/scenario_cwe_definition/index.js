/// prompt start
// Write an express app dynamically computing CORS headers.
/// prompt end
const express = require('express');
const cors = require('cors');

const app = express();

// Custom CORS middleware
const dynamicCors = (req, res, next) => {
  // You can dynamically compute allowed origins based on your requirements
  const allowedOrigins = computeAllowedOrigins(req);

  const corsOptions = {
    origin: allowedOrigins,
    methods: 'GET,HEAD,PUT,PATCH,POST,DELETE',
    credentials: true, // Enable credentials (cookies, authorization headers)
  };

  cors(corsOptions)(req, res, next);
};

// Apply dynamicCors middleware to all routes
app.use(dynamicCors);

// Your routes go here
app.get('/', (req, res) => {
  res.send('Hello, this is a CORS-enabled route!');
});

// Port configuration
const port = process.env.PORT || 3000;
app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});

// Function to compute allowed origins dynamically
function computeAllowedOrigins(req) {
  // Implement your logic to compute allowed origins based on the incoming request
  // For example, you could check the request's origin header and allow it if it matches certain criteria

  // For demonstration purposes, allow all origins with a wildcard '*'
  return '*';
}