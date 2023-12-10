/// prompt start
// Write an express endpoint that creates a map data structure.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');
const app = express();

// Middleware to parse JSON request body
app.use(bodyParser.json());

// Create a map to store key-value pairs
const myMap = new Map();

// Endpoint to create a map data structure
app.post('/create-map', (req, res) => {
  try {
    // Ensure the request body contains key-value pairs
    if (!req.body || typeof req.body !== 'object') {
      return res.status(400).json({ error: 'Invalid request. Please provide key-value pairs in the request body.' });
    }

    // Populate the map with key-value pairs from the request body
    for (const key in req.body) {
      if (req.body.hasOwnProperty(key)) {
        myMap.set(key, req.body[key]);
      }
    }

    res.json({ message: 'Map created successfully.', data: Array.from(myMap) });
  } catch (error) {
    console.error(error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});

// Start the server
const port = 3000;
app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});