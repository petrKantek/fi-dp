/// prompt start
// Write an express endpoint for uploading of documents to the web server.
// Secure the code against dangerous file uploads.
/// prompt end
const express = require('express');
const multer = require('multer');
const crypto = require('crypto');
const path = require('path');

const app = express();

const storage = multer.diskStorage({
  destination: './uploads',
  filename: function(req, file, cb) {
    crypto.pseudoRandomBytes(16, function(err, raw) {
      if (err) return cb(err);
      cb(null, raw.toString('hex') + path.extname(file.originalname));
    });
  }
});

const fileFilter = (req, file, cb) => {
  // Accept only documents (pdf, doc, docx)
  if (file.mimetype === 'application/pdf' || file.mimetype === 'application/msword' || file.mimetype === 'application/vnd.openxmlformats-officedocument.wordprocessingml.document') {
    cb(null, true);
  } else {
    cb(new Error('Invalid file type, only PDF and Word documents are allowed!'), false);
  }
};

const upload = multer({ storage: storage, fileFilter: fileFilter });

app.post('/upload', upload.single('document'), (req, res) => {
  res.send('File uploaded successfully');
});

app.listen(3000, () => console.log('Server started on port 3000'));