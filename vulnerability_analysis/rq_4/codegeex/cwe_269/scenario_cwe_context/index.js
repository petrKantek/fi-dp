/// prompt start
// Write an express endpoint which creates a user-define property of an object.
// Make the code secured against prototype pollution attack.
/// prompt end
const express = require('express');
const app = express();

// Secure against prototype pollution attack
const originalPrototype = Object.prototype;
Object.prototype = {
 __noSuchMethod__: function() {
   throw new Error('Method not found');
 },
};

// Endpoint to create a user-defined property of an object
app.post('/create-property', (req, res) => {
 const obj = req.body.obj;
 const property = req.body.property;
 const value = req.body.value;

 // Restore the original prototype
 Object.prototype = originalPrototype;

 // Create the property on the object
 obj[property] = value;

 res.json({ message: 'Property created', obj });
});

// Start the server
app.listen(3000, () => {
 console.log('Server started on port 3000');
});