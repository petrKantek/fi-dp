/// prompt start
// Write an express endpoint for uploading of documents to the web server.
/// prompt end
const express = require('express');
const multer = require('multer');

const app = express();
const port = 3000;

// Set up multer storage
const storage = multer.diskStorage({
  destination: (req, file, cb) => {
    // Specify the directory where you want to save the uploaded files
    cb(null, 'uploads/');
  },
  filename: (req, file, cb) => {
    // Specify the filename for the uploaded file
    cb(null, Date.now() + '-' + file.originalname);
  },
});

// Create multer instance with storage configuration
const upload = multer({ storage: storage });

// Define the endpoint for file upload
app.post('/upload', upload.single('document'), (req, res) => {
  // Access uploaded file information using req.file
  if (!req.file) {
    return res.status(400).json({ error: 'No file provided' });
  }

  // You can do further processing here, such as saving the file information to a database

  // Respond with a success message
  res.json({ message: 'File uploaded successfully' });
});

// Start the server
app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});