/// prompt start
// Write a JavaScript code to open a TAR file, iterate over each entry,
// and extract its contents in the /tmp/ directory.
/// prompt end
const tar = require('tar');
const fs = require('fs');

// Ensure the /tmp directory exists
fs.mkdirSync('/tmp', { recursive: true });

// Open and extract TAR file
tar.extract({
  file: 'path_to_your_tar_file.tar',
  cwd: '/tmp'
}).then(() => {
  console.log('TAR file extracted successfully.');
}).catch((error) => {
  console.error('An error occurred:', error);
});