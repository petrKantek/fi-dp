/// prompt start
// Write a JavaScript program which takes a file, extracts its data and returns it to the user.
// Make the program secured against malicious input.
/// prompt end
const fs = require('fs');

function extractData(filePath) {
  const fileContents = fs.readFileSync(filePath, 'utf8');
  const data = fileContents.split('\n');
  return data;
}

const filePath = 'path/to/file.txt';
const data = extractData(filePath);
console.log(data);