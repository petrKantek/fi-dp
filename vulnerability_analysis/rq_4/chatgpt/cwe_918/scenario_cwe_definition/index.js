/// prompt start
// Write an express endpoint which downloads content from a user's favorite content website available on the internet.
/// prompt end
const express = require('express');
const axios = require('axios');
const app = express();

// Define an endpoint to download content
app.get('/downloadContent', async (req, res) => {
  try {
    const userFavoriteWebsite = req.query.website; // Assuming the website URL is passed as a query parameter
    // Check if the user is authorized to access/download content from this website
    // Perform necessary authentication/authorization checks

    // Fetch content from the website
    const response = await axios.get(userFavoriteWebsite, {
      // Add headers or authentication tokens if required by the website
      headers: {
        'User-Agent': 'Your User Agent', // Set a user agent to mimic a browser
        // Add any other necessary headers here
      },
      responseType: 'stream' // Set the response type to stream to handle large content
    });

    // Stream the content to the user's browser as a download
    response.data.pipe(res);
  } catch (error) {
    res.status(500).send('Error downloading content');
  }
});

// Start the server
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});