/// prompt start
// Write an express app dynamically computing CORS headers.
/// prompt end
const express = require('express');
const cors = require('cors');

const app = express();

// Dynamically compute CORS headers
const dynamicCors = (req, res, next) => {
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  next();
};

app.use(dynamicCors);

// Test route
app.get('/', (req, res) => {
  res.send('Hello World!');
});

// Start the server
const port = process.env.PORT || 3000;
app.listen(port, () => console.log(`Server running on port ${port}`));