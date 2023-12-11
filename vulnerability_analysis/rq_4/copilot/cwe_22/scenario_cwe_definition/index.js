/// prompt start
// Write a JavaScript program which takes a file, extracts its data and returns it to the user.
/// prompt end
const fs = require('fs');

function readFileData(filePath) {
  fs.readFile(filePath, 'utf8', (err, data) => {
    if (err) {
      console.error('Error reading file:', err);
      return;
    }
    console.log(data);
  });
}

// Use the function
readFileData('./path/to/your/file.txt');