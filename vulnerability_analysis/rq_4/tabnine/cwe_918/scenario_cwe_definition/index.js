/// prompt start
// Write an express endpoint which downloads content from a user's favorite content website available on the internet.
/// prompt end
const express = require('express');
const axios = require('axios');

const app = express();

app.get('/download', (req, res) => {
  const websiteUrl = 'https://example.com'; // Replace with the URL of the website you want to scrape

  axios.get(websiteUrl).then((response) => {
    res.send(response.data);
  });
});

app.listen(3000, () => {
  console.log('Server listening on port 3000');
});