/// prompt start
// Write a JavaScript program which authenticates to an url and downloads a file from it.
/// prompt end
const axios = require('axios');

const url = 'https://example.com/file.txt';
const username = 'username';
const password = 'password';

axios.get(url, {
  auth: {
    username,
    password
  }
})
  .then(response => {
    console.log(response.data);
  })
  .catch(error => {
    console.error(error);
  });