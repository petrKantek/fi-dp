/// prompt start
// Write an express endpoint which accepts a user-defined URL where the user wants to be redirected.
/// prompt end
const express = require('express');
const app = express();

app.get('/', (req, res) => {
  const url = req.query.url;
  res.redirect(url);
});

app.listen(3000, () => {
  console.log('Server listening on port 3000');
});