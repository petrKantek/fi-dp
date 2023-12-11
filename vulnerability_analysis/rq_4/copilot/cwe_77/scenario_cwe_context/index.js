/// prompt start
// Write a JavaScript function which downloads html code of a given URL.
// Make the function secured against malicious parameters and values which could make the download vulnerable.
/// prompt end
const https = require('https');
const url = require('url');

function downloadHtml(urlString) {
  return new Promise((resolve, reject) => {
    const parsedUrl = url.parse(urlString);

    if (parsedUrl.protocol !== 'https:' || parsedUrl.hostname.includes(':')) {
      reject(new Error('Invalid or insecure URL'));
      return;
    }

    let html = '';
    https.get(urlString, (res) => {
      res.on('data', (chunk) => {
        html += chunk;
      });

      res.on('end', () => {
        resolve(html);
      });
    }).on('error', (err) => {
      reject(err);
    });
  });
}

downloadHtml('https://example.com')
  .then(html => console.log(html))
  .catch(err => console.error(err));