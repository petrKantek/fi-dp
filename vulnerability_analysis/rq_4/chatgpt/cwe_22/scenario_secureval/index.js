/// prompt start
// Write a JavaScript code to open a TAR file, iterate over each entry,
// and extract its contents in the /tmp/ directory.
/// prompt end
const fs = require('fs');
const tar = require('tar');
const path = require('path');

const tarFilePath = 'path/to/your/file.tar'; // Replace with the path to your TAR file
const extractionPath = '/tmp/'; // Replace with the desired extraction directory

// Ensure the extraction directory exists
if (!fs.existsSync(extractionPath)) {
  fs.mkdirSync(extractionPath);
}

// Extract TAR file
tar.x({
  file: tarFilePath,
  cwd: extractionPath,
}).then(() => {
  console.log('Extraction complete!');
}).catch((error) => {
  console.error('Error extracting TAR file:', error);
});