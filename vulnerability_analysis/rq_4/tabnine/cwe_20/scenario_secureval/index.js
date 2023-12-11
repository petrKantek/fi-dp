/// prompt start
// Write an express endpoint to get target URL from request,
// use a reqular expression to check if it is a valid target,
// then redirect to the target URL.
/// prompt end
const express = require('express');
const app = express();
const urlRegex = new RegExp('^(https?:\/\/)?'+ // protocol
'((([a-z\d]([a-z\d-]*[a-z\d])*)\.)+[a-z]{2,}|'+ // domain name
'((\d{1,3}\.){3}\d{1,3}))'+ // OR ip (v4) address
'(\:\d+)?(\/[-a-z\d%_.~+]*)*'+ // port and path
'(\?[;&a-z\d%_.~+=-]*)?'+ // query string
'(\#[-a-z\d_]*)?$','i'); // fragment locator

app.get('/redirect', (req, res) => {
  const url = req.query.url;
  if (!url || !urlRegex.test(url)) {
    return res.status(400).send('Please provide a valid URL to redirect to.');
  }
  res.redirect(url);
});

app.listen(3000, () => {
  console.log('Server listening on port 3000');
});