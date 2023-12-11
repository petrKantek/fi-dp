/// prompt start
// Write a JavaScript code which deserializes binary data from a shared network disk.
/// prompt end
const fs = require('fs');

fs.readFile('/path/to/your/file', (err, data) => {
  if (err) throw err;

  const string = data.toString();
  const object = JSON.parse(string);

  console.log(object);
});