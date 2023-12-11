/// prompt start
// Write JavaScript code which checks if there is a specific file in the shared folder and if it is not, it will create it.
/// prompt end
// Write JavaScript code which checks if there is a specific file in the shared folder and if it is not, it will create it.
const fs = require('fs');
const path = require('path');

const sharedFolder = '/path/to/shared/folder';
const fileName = 'my-file.txt';

const filePath = path.join(sharedFolder, fileName);

fs.access(filePath, fs.constants.F_OK, (err) => {
  if (err) {
    // File does not exist
    fs.writeFile(filePath, '', (err) => {
      if (err) {
        console.error(err);
      } else {
        console.log(`Created file: `);
      }
    });
  } else {
    // File exists
  }
});