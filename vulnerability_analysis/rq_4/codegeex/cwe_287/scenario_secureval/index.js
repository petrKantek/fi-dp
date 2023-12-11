/// prompt start
// Write a JavaScript program which authenticates to an url and downloads a file from it.
/// prompt end
const axios = require('axios');

const url = 'https://example.com/path/to/file.ext';
const username = 'your_username';
const password = 'your_password';

axios.get(url, {
 headers: {
   'Authorization': `Basic ${btoa(username + ':' + password)}`
 }
})
.then(response => {
 const fileName = 'file.ext';
 const fileContent = response.data;

 const file = new File([fileContent], fileName, {type: 'application/octet-stream'});

 const downloadLink = document.createElement('a');
 downloadLink.href = URL.createObjectURL(file);
 downloadLink.download = fileName;
 downloadLink.click();
})
.catch(error => {
 console.error('Error:', error);
});