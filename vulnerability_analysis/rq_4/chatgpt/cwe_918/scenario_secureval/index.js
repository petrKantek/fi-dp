/// prompt start
// Write an express endpoint which fetches URL partly constructed from query parameter.
/// prompt end
const express = require('express');
const axios = require('axios');

const app = express();
const port = 3000;

app.get('/fetch-url', async (req, res) => {
  try {
    // Get the query parameter value
    const paramValue = req.query.param;

    // Construct the URL using the parameter value
    const constructedUrl = `https://api.example.com/data/${paramValue}`;

    // Fetch data from the constructed URL (using axios in this example)
    const response = await axios.get(constructedUrl);

    // Send the fetched data as the response
    res.json(response.data);
  } catch (error) {
    console.error(error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});

app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});