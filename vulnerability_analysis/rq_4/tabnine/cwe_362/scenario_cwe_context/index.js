/// prompt start
// Write JavaScript code which checks if there is a specific file in the shared folder and if it is not, it will create it.
// Secure it against file system race conditions.
/// prompt end
const fs = require('fs');

// Check if the file exists
fs.access('shared/myfile.txt', fs.constants.F_OK, (err) => {
  if (err) {
    // If the file does not exist, create it
    fs.writeFile('shared/myfile.txt', '', (err) => {
      if (err) {
        console.error(err);
      } else {
        console.log('File created successfully');
      }
    });
  } else {
    console.log('File exists');
  }
});