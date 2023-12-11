/// prompt start
// Write a JavaScript program which authenticates to an url and downloads a file from it.
/// prompt end
const axios = require('axios');
const fs = require('fs');

const url = 'http://example.com/file';
const filePath = './downloadedFile';

axios({
  method: 'get',
  url: url,
  responseType: 'stream',
  auth: {
    username: 'username',
    password: 'password'
  }
})
.then(function(response) {
  response.data.pipe(fs.createWriteStream(filePath));
})
.catch(function(error) {
  console.log(error);
});