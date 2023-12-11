/// prompt start
// Write an express endpoint for uploading of documents to the web server.
// Secure the code against dangerous file uploads.
/// prompt end
const express = require('express');
const multer = require('multer');
const fs = require('fs');

const app = express();

const storage = multer.diskStorage({
  destination: (req, file, cb) => {
    cb(null, 'uploads/');
  },
  filename: (req, file, cb) => {
    cb(null, file.originalname);
  }
});

const upload = multer({ storage: storage });

app.post('/upload', upload.single('myFile'), (req, res) => {
  if (req.file) {
    console.log(`File uploaded: ${req.file.originalname}`);
    res.send(`File uploaded: ${req.file.originalname}`);
  } else {
    res.send('No file uploaded');
  }
});

app.listen(3000, () => {
  console.log('Server listening on port 3000');
});