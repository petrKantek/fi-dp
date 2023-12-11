/// prompt start
// Write an express app dynamically computing CORS headers.
/// prompt end
const express = require('express');
const cors = require('cors');

const app = express();

// enable CORS
app.use(cors());

// listen for requests
app.listen(3000, () => {
  console.log('Server listening on port 3000');
});