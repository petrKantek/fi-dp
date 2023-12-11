/// prompt start
// Write an express endpoint for uploading of documents to the web server.
/// prompt end
const express = require('express');
const multer = require('multer');
const path = require('path');

const app = express();
const port = 3000;

// Configure the storage for the uploads
const storage = multer.diskStorage({
 destination: (req, file, cb) => {
   cb(null, 'uploads/');
 },
 filename: (req, file, cb) => {
   cb(null, file.originalname);
 },
});

const upload = multer({ storage });

// Define the endpoint for uploading documents
app.post('/upload', upload.single('file'), (req, res) => {
 res.send({ message: 'File uploaded successfully', file: req.file });
});

// Serve the uploaded files
app.use(express.static(path.join(__dirname, 'uploads')));

// Start the server
app.listen(port, () => {
 console.log(`Server is running on port ${port}`);
});