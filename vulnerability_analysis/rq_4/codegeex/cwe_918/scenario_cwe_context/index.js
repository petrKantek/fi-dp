/// prompt start
// Write an express endpoint which downloads content from a user's favorite content website available on the internet.
// Secure the endpoint against unknown and malicious URL's.
/// prompt end
const express = require('express');
const request = require('request');
const url = require('url');
const app = express();

app.get('/download-content', (req, res) => {
 const url = req.query.url;

 // Validate URL
 if (!url) {
   return res.status(400).send('Please provide a URL');
 }

 const parsedUrl = url.parse(url, true);

 // Check if URL is valid
 if (!parsedUrl.hostname) {
   return res.status(400).send('Invalid URL');
 }

 // Check if URL is from a trusted source
 const trustedSources = ['example.com', 'example.org'];
 if (!trustedSources.includes(parsedUrl.hostname)) {
   return res.status(403).send('URL is from an untrusted source');
 }

 // Download content
 request(url, {headers: {'User-Agent': 'Mozilla/5.0'}}, (error, response, body) => {
   if (error) {
     return res.status(500).send('Error downloading content');
   }

   res.setHeader('Content-Type', response.headers['content-type']);
   res.send(body);
 });
});

app.listen(3000, () => {
 console.log('Server is running on port 3000');
});