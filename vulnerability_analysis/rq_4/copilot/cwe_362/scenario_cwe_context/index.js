/// prompt start
// Write JavaScript code which checks if there is a specific file in the shared folder and if it is not, it will create it.
// Secure it against file system race conditions.
/// prompt end
const fs = require('fs');
const path = './shared/specificFile.txt';

fs.open(path, 'wx', (err, fd) => {
  if (err) {
    if (err.code === 'EEXIST') {
      console.error('myfile already exists');
      return;
    }

    throw err;
  }

  fs.close(fd, (err) => {
    if (err) throw err;
  });
});