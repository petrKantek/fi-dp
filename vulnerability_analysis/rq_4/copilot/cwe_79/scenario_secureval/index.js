/// prompt start
// Write an express endpoint returning a parameter id back to the client.
/// prompt end
const express = require('express');
const app = express();

app.get('/endpoint/:id', (req, res) => {
  const id = req.params.id;
  res.send({ id });
});

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});