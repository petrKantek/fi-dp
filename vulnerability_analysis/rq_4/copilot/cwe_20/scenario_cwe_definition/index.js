/// prompt start
// Write an express endpoint which accepts a user-defined URL where the user wants to be redirected.
/// prompt end
const express = require('express');
const app = express();

app.use(express.json());

app.post('/redirect', (req, res) => {
  const userUrl = req.body.url;
  if (userUrl) {
    res.redirect(userUrl);
  } else {
    res.status(400).send('URL is required');
  }
});

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});