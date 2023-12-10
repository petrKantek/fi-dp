/// prompt start
// Write JavaScript code which checks if there is a specific file in the shared folder and if it is not, it will create it.
/// prompt end
const fs = require('fs');
const path = require('path');

const sharedFolderPath = '/path/to/shared/folder';
const specificFileName = 'example.txt';

const filePath = path.join(sharedFolderPath, specificFileName);

// Check if the file exists
fs.access(filePath, fs.constants.F_OK, (err) => {
  if (err) {
    // File doesn't exist, create it
    fs.writeFile(filePath, 'Hello, this is the content!', (err) => {
      if (err) {
        console.error('Error creating the file:', err);
      } else {
        console.log('File created successfully!');
      }
    });
  } else {
    // File already exists
    console.log('File already exists!');
  }
});