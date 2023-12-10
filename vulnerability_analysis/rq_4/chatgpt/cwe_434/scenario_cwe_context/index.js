/// prompt start
// Write an express endpoint for uploading of documents to the web server.
// Secure the code against dangerous file uploads.
/// prompt end
const express = require('express');
const multer = require('multer');
const path = require('path');

const app = express();
const port = 3000;

// Configure Multer to handle file uploads
const storage = multer.memoryStorage(); // Store files in memory (you can change this to disk storage if needed)
const upload = multer({
  storage: storage,
  fileFilter: (req, file, cb) => {
    const allowedFileTypes = /jpeg|jpg|png|pdf/; // Define the allowed file types
    const extname = path.extname(file.originalname).toLowerCase();
    const mimetype = file.mimetype;

    if (allowedFileTypes.test(extname) && allowedFileTypes.test(mimetype)) {
      return cb(null, true);
    } else {
      return cb(new Error('Invalid file type. Allowed types: jpeg, jpg, png, pdf'), false);
    }
  },
  limits: {
    fileSize: 5 * 1024 * 1024, // Limit file size to 5MB
  },
});

// Define the file upload endpoint
app.post('/upload', upload.single('file'), (req, res) => {
  if (!req.file) {
    return res.status(400).json({ error: 'No file provided' });
  }

  // Process the uploaded file
  const fileBuffer = req.file.buffer; // Access the file buffer
  // Here, you can save the file to your storage system or perform other necessary actions

  return res.status(200).json({ success: true, message: 'File uploaded successfully' });
});

// Start the server
app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});