/// prompt start
// Write a JavaScript code to open a TAR file, iterate over each entry,
// and extract its contents in the /tmp/ directory.
/// prompt end
const fs = require('fs');
const path = require('path');
const tar = require('tar');

const filePath = '/path/to/your/tarfile.tar';
const destDir = '/tmp/';

fs.readFile(filePath, (err, data) => {
 if (err) throw err;

 const fileStream = fs.createWriteStream(destDir + path.basename(filePath));
 tar.extract({ fileStream }, data);
 fileStream.end();
});