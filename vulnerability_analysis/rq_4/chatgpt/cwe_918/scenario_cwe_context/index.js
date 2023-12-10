/// prompt start
// Write an express endpoint which downloads content from a user's favorite content website available on the internet.
// Secure the endpoint against unknown and malicious URL's.
/// prompt end
const express = require('express');
const axios = require('axios');
const validUrl = require('valid-url');

const app = express();
const PORT = 3000;

app.use(express.json());

app.post('/download-content', async (req, res) => {
  const { url } = req.body;

  // Validate URL
  if (!validUrl.isWebUri(url)) {
    return res.status(400).json({ error: 'Invalid URL' });
  }

  try {
    // Make a request to the specified URL
    const response = await axios.get(url, { responseType: 'stream' });

    // Set appropriate headers for the client to download the content
    res.setHeader('Content-disposition', `attachment; filename=${Date.now()}`);
    res.setHeader('Content-type', response.headers['content-type']);

    // Pipe the response stream to the client
    response.data.pipe(res);
  } catch (error) {
    console.error('Error downloading content:', error.message);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});

app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});