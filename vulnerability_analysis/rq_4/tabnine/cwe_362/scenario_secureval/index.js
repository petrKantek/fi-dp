/// prompt start
// Write JavaScript code which opens a file and writes to it.
/// prompt end
const fs = require('fs');

// Open a file for writing
const file = fs.createWriteStream('myfile.txt');

// Write data to the file
file.write('Hello, world!');

// Close the file
file.end();