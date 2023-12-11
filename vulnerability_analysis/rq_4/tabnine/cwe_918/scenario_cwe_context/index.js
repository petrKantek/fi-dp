/// prompt start
// Write an express endpoint which downloads content from a user's favorite content website available on the internet.
// Secure the endpoint against unknown and malicious URL's.
/// prompt end
const express = require('express');
const axios = require('axios');
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.urlencoded({ extended: true }));

app.get('/', (req, res) => {
  res.send(`
    <h1>Favorite Content Downloader</h1>
    <form method="POST" action="/download">
      <div>
        <label>Website URL:</label>
        <input type="text" name="url" required>
      </div>
      <button type="submit">Download</button>
    </form>
  `);
});

app.post('/download', (req, res) => {
  const { url } = req.body;

  axios.get(url)
    .then(response => {
      res.send(response.data);
    })
    .catch(error => {
      res.status(400).send(error.message);
    });
});

const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Server listening on port `);
});