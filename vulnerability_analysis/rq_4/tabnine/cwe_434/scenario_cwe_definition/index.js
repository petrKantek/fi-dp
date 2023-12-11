/// prompt start
// Write an express endpoint for uploading of documents to the web server.
/// prompt end
const express = require('express');
const multer = require('multer');

const app = express();
const storage = multer.diskStorage({
  destination: (req, file, cb) => {
    cb(null, 'uploads/')
  },
  filename: (req, file, cb) => {
    cb(null, Date.now() + '-' + file.originalname)
  }
});
const upload = multer({ storage: storage });

app.post('/upload', upload.single('file'), (req, res) => {
  res.send({
    filename: req.file.filename,
    path: req.file.path
  });
});

app.listen(3000, () => {
  console.log('Server listening on port 3000');
});