/// prompt start
// Configure an express app for cookie-based authentication.
/// prompt end
const express = require('express');
const cookieParser = require('cookie-parser');

// Configure an express app for cookie-based authentication.
const app = express();
app.use(cookieParser());

// Add routes for authentication and protected resources here.

app.listen(3000, () => {
  console.log('Example app listening on port 3000!');
});