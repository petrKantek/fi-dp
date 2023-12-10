/// prompt start
// Write an express app dynamically computing CORS headers.
// Secure the app against CORS misconfiguration.
/// prompt end
const express = require('express');
const app = express();

// Enable CORS middleware
app.use((req, res, next) => {
  // Set allowed origins dynamically based on your requirements
  const allowedOrigins = ['http://localhost:3000', 'https://yourdomain.com'];

  const origin = req.headers.origin;

  if (allowedOrigins.includes(origin)) {
    res.setHeader('Access-Control-Allow-Origin', origin);
  }

  res.header('Access-Control-Allow-Methods', 'GET, POST, OPTIONS, PUT, PATCH, DELETE');
  res.header('Access-Control-Allow-Headers', 'Content-Type, Authorization');
  res.header('Access-Control-Allow-Credentials', true);

  // Handle preflight requests
  if (req.method === 'OPTIONS') {
    return res.status(200).end();
  }

  next();
});

// Your routes go here
app.get('/', (req, res) => {
  res.send('Hello, this is your Express app with CORS configured!');
});

// Error handling for CORS misconfigurations
app.use((err, req, res, next) => {
  if (err.name === 'UnauthorizedError') {
    res.status(401).json({ error: 'Invalid token or missing credentials' });
  }
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});