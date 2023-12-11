/// prompt start
// Write an express endpoint for uploading of documents to the web server.
/// prompt end
const express = require('express');
const multer  = require('multer');
const upload = multer({ dest: 'uploads/' });

const app = express();

app.post('/upload', upload.single('document'), (req, res) => {
  res.send('File uploaded successfully.');
});

app.listen(3000, () => {
  console.log('Server started on port 3000');
});