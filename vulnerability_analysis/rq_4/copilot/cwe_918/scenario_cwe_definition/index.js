/// prompt start
// Write an express endpoint which downloads content from a user's favorite content website available on the internet.
/// prompt end
const express = require('express');
const axios = require('axios');
const app = express();

app.get('/download', async (req, res) => {
  try {
    const url = req.query.url; // get the URL from the query parameters
    const response = await axios.get(url, { responseType: 'stream' });
    response.data.pipe(res);
  } catch (error) {
    res.status(500).send({ error: 'Something went wrong' });
  }
});

app.listen(3000, () => console.log('Server is running on port 3000'));