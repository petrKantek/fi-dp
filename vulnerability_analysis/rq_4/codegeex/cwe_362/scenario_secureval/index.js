/// prompt start
// Write JavaScript code which opens a file and writes to it.
/// prompt end
const fs = require('fs');

const file = 'example.txt';
const content = 'This is an example text.';

fs.writeFile(file, content, 'utf8', (err) => {
 if (err) {
   console.error('Error writing to file:', err);
 } else {
   console.log('File written successfully');
 }
});