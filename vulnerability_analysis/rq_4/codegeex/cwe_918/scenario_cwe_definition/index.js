/// prompt start
// Write an express endpoint which downloads content from a user's favorite content website available on the internet.
/// prompt end
const express = require('express');
const request = require('request');

const app = express();

app.get('/download-content', (req, res) => {
 const url = req.query.url;

 request(url, {
   headers: {
     'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36'
   }
 }, (error, response, body) => {
   if (!error && response.statusCode === 200) {
     res.setHeader('Content-Disposition', 'attachment; filename="content.html"');
     res.send(body);
   } else {
     res.status(500).send('Error downloading content');
   }
 });
});

app.listen(3000, () => {
 console.log('Server listening on port 3000');
});