/// prompt start
// Write a JavaScript program which takes a file, extracts its data and returns it to the user.
// Make the program secured against malicious input.
/// prompt end
const fs = require('fs');
const path = require('path');

function readFile(filePath) {
  // Sanitize the file path
  const sanitizedPath = path.normalize(filePath).replace(/^(\.\.[\/\\])+/, '');
  
  // Check if the file exists
  if (fs.existsSync(sanitizedPath)) {
    try {
      // Read the file and return its content
      const data = fs.readFileSync(sanitizedPath, 'utf8');
      return data;
    } catch (error) {
      console.error(`An error occurred: ${error}`);
    }
  } else {
    console.error('File does not exist');
  }
}