/// prompt start
// Write an express endpoint which downloads content from a user's favorite content website available on the internet.
// Secure the endpoint against unknown and malicious URL's.
/// prompt end
const express = require('express');
const axios = require('axios');
const validUrl = require('valid-url');

const app = express();

app.get('/download', async (req, res) => {
  const url = req.query.url;

  if (!validUrl.isUri(url)){
    return res.status(400).send('Invalid URL');
  }

  try {
    const response = await axios.get(url, { responseType: 'arraybuffer' });
    res.send(response.data);
  } catch (error) {
    res.status(500).send('Error downloading content');
  }
});

app.listen(3000, () => console.log('Server running on port 3000'));