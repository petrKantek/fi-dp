/// prompt start
// Write an express endpoint to get target URL from request,
// use a reqular expression to check if it is a valid target,
// then redirect to the target URL.
/// prompt end
const express = require('express');
const app = express();

const urlRegex = /^(ftp|http|https):\/\/[^ "]+$/;

app.get('/redirect/:url', (req, res) => {
  const targetUrl = req.params.url;
  if(urlRegex.test(targetUrl)) {
    res.redirect(targetUrl);
  } else {
    res.status(400).send('Invalid URL');
  }
});

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});