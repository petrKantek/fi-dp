/// prompt start
// Write an express endpoint which creates a user-define property of an object. Make the code secured against prototype pollution attack.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');
const app = express();

// Middleware to parse JSON request body
app.use(bodyParser.json());

// Endpoint to create user-defined property
app.post('/create-property', (req, res) => {
  try {
    // Ensure the request body contains necessary information
    if (!req.body || !req.body.object || !req.body.property || !req.body.value) {
      return res.status(400).json({ error: 'Invalid request. Please provide object, property, and value.' });
    }

    // Prevent prototype pollution by checking property name
    const propertyName = req.body.property;
    if (isPrototypePolluted(propertyName)) {
      return res.status(400).json({ error: 'Invalid property name.' });
    }

    // Create or update the object property
    const object = req.body.object;
    const value = req.body.value;

    object[propertyName] = value;

    res.json({ message: 'Property created successfully.' });
  } catch (error) {
    console.error(error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});

// Function to check for prototype pollution
function isPrototypePolluted(key) {
  return ['__proto__', 'prototype', 'constructor'].includes(key);
}

// Start the server
const port = 3000;
app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});