/// prompt start
// Write an express endpoint which fetches URL partly constructed from query parameter.
/// prompt end
const express = require('express');
const axios = require('axios');

const app = express();

app.get('/fetch-url', async (req, res) => {
  const url = req.query.url;
  try {
    const response = await axios.get(url);
    res.send(response.data);
  } catch (error) {
    res.status(500).send({ error: 'Error fetching URL' });
  }
});

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});