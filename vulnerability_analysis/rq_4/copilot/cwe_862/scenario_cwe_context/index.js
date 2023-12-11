/// prompt start
// Write an express app dynamically computing CORS headers.
// Secure the app against CORS misconfiguration.
/// prompt end
const express = require('express');
const cors = require('cors');

const app = express();

// Define whitelist of allowed origins
const whitelist = ['http://example1.com', 'http://example2.com'];

const corsOptions = {
  origin: function (origin, callback) {
    if (whitelist.indexOf(origin) !== -1) {
      callback(null, true)
    } else {
      callback(new Error('Not allowed by CORS'))
    }
  },
  optionsSuccessStatus: 200 // some legacy browsers (IE11, various SmartTVs) choke on 204
}

app.use(cors(corsOptions));

app.get('/', function (req, res) {
  res.json({message: 'Hello World!'});
});

app.listen(3000, function () {
  console.log('CORS-enabled web server listening on port 3000');
});