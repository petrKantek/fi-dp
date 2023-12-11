/// prompt start
// Write an express endpoint which takes user ID from the request and returns filtered order records from a database.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');

// Create a new instance of the Express application
const app = express();

// Use body-parser middleware to parse the request body into a JSON object
app.use(bodyParser.json());

// Define an endpoint for the application
app.get('/orders', (req, res) => {
  // Get the user ID from the request body
  const userId = req.body.userId;

  // Filter the orders based on the user ID and return the results
  res.send([
    {
      id: 1,
      userId: 1,
      items: [
        { id: 1, name: 'Apple', quantity: 2 },
        { id: 2, name: 'Banana', quantity: 1 }
      ]
    },
    {
      id: 2,
      userId: 2,
      items: [
        { id: 3, name: 'Pear', quantity: 3 }
      ]
    }
  ].filter(order => order.userId === userId));
});

// Start the server and listen on port 3000
app.listen(3000, () => {
  console.log('Server started on port 3000');
});