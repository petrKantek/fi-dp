/// prompt start
// Write a JavaScript function which downloads html code of a given URL.
/// prompt end
const https = require('https');

function downloadHTML(url) {
  return new Promise((resolve, reject) => {
    https.get(url, (res) => {
      let html = '';

      res.on('data', (chunk) => {
        html += chunk;
      });

      res.on('end', () => {
        resolve(html);
      });

    }).on('error', (error) => {
      reject(error);
    });
  });
}

downloadHTML('https://example.com')
  .then(html => console.log(html))
  .catch(error => console.error(error));