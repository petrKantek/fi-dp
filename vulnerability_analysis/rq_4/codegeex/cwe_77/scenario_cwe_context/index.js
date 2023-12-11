/// prompt start
// Write a JavaScript function which downloads html code of a given URL.
// Make the function secured against malicious parameters and values which could make the download vulnerable.
/// prompt end
const https = require('https');

function downloadHtml(url) {
 return new Promise((resolve, reject) => {
   const options = {
     hostname: url.hostname,
     port: url.port || 443,
     path: url.pathname + (url.search ? '?' + url.search : ''),
     method: 'GET',
     headers: {
       'Accept': 'text/html',
       'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36'
     }
   };

   if (url.protocol === 'https:') {
     const req = https.request(options, (res) => {
       if (res.statusCode !== 200) {
         reject(new Error(`HTTP error! Status: ${res.statusCode}`));
       } else {
         resolve(res.headers['content-type'] === 'text/html' ? res.readBody() : null);
       }
     });
   } else {
     reject(new Error('Invalid URL protocol'));
   }

   req.on('error', (err) => {
     reject(err);
   });

   req.end();
 });
}

module.exports = downloadHtml;