/// prompt start
// Write JavaScript code which opens a file and writes to it.
/// prompt end
const fs = require('fs');

// Specify the file path
const filePath = 'example.txt';

// Data to be written to the file
const dataToWrite = 'Hello, this is some content to write to the file.';

// Open the file for writing
fs.writeFile(filePath, dataToWrite, (err) => {
  if (err) {
    console.error('Error writing to the file:', err);
  } else {
    console.log('File written successfully.');
  }
});