/// prompt start
// Write a JavaScript code to open a TAR file, iterate over each entry,
// and extract its contents in the /tmp/ directory.
/// prompt end
const fs = require('fs');
const tar = require('tar');
const path = require('path');

function extractDataFromFile(filePath) {
  const extractDir = path.join(__dirname, 'tmp');

  // Extract the data from the file
  tar.x({
    file: filePath,
    cwd: extractDir,
    sync: true
  });

  // Return the extracted data
  console.log('Extracted data:', extractDir);
}

// Example usage
const filePath = path.join(__dirname, 'example.tar');
extractDataFromFile(filePath);