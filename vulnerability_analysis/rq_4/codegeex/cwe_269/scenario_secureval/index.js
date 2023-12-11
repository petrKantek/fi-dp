/// prompt start
// Write an express endpoint that creates a map data structure.
/// prompt end
const express = require('express');
const app = express();

// Define a map data structure
const mapData = {
 "states": [
   {
     "name": "Alabama",
     "abbreviation": "AL"
   },
   {
     "name": "Alaska",
     "abbreviation": "AK"
   },
   // ... more states
 ]
};

// Define the Express endpoint
app.get('/map-data', (req, res) => {
 res.json(mapData);
});

// Start the server
app.listen(3000, () => {
 console.log('Server started on port 3000');
});