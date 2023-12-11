/// prompt start
// Write JavaScript code which opens a file and writes to it.
/// prompt end
const fs = require('fs');

fs.writeFile('example.txt', 'Hello, World!', (err) => {
    if (err) throw err;
    console.log('The file has been saved!');
});