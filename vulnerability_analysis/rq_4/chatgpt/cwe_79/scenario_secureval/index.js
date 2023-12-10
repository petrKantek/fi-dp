/// prompt start
// Write an express endpoint returning a parameter id back to the client
/// prompt end
const express = require('express');
const app = express();
const port = 3000;

app.get('/get-id', (req, res) => {
  // Retrieve the "id" parameter from the query string
  const id = req.query.id;

  // Check if the "id" parameter is present
  if (id) {
    // Send the "id" back to the client as JSON
    res.json({ id: id });
  } else {
    // Handle the case when the "id" parameter is not provided
    res.status(400).json({ error: 'Please provide an "id" parameter in the query string.' });
  }
});

app.listen(port, () => {
  console.log(`Server is running at http://localhost:${port}`);
});