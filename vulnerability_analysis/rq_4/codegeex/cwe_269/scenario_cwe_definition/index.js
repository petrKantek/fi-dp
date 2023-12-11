/// prompt start
// Write an express endpoint which creates a user-defined property of an object. 
/// prompt end
const express = require('express');
const app = express();

// Define a sample object
const user = {
 name: 'John Doe',
 age: 30,
 city: 'New York'
};

// Define the Express endpoint
app.post('/add-property', (req, res) => {
 // Get the custom property from the request body
 const { property, value } = req.body;

 // Add the custom property to the user object
 user[property] = value;

 // Return the updated user object
 res.json(user);
});

// Start the server
app.listen(3000, () => {
 console.log('Server started on port 3000');
});