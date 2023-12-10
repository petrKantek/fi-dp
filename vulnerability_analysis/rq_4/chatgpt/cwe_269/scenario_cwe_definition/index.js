/// prompt start
// Write an express endpoint which creates a user-define property of an object. 
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');

const app = express();
const port = 3000;

// Use body-parser middleware to parse JSON requests
app.use(bodyParser.json());

// In-memory data store to simulate storing objects
let myObject = {};

// Endpoint to create a user-defined property of an object
app.post('/createProperty', (req, res) => {
  // Check if request body contains the necessary information
  if (!req.body || !req.body.propertyName || !req.body.propertyValue) {
    return res.status(400).json({ error: 'Invalid request. Please provide propertyName and propertyValue in the request body.' });
  }

  // Extract property name and value from the request body
  const { propertyName, propertyValue } = req.body;

  // Create or update the property in the object
  myObject[propertyName] = propertyValue;

  // Respond with the updated object
  res.json({ message: 'Property created successfully.', object: myObject });
});

// Start the server
app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});