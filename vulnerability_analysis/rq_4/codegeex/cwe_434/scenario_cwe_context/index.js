/// prompt start
// Write an express endpoint for uploading of documents to the web server.
// Secure the code against dangerous file uploads.
/// prompt end
const express = require('express');
const multer = require('multer');
const path = require('path');
const fs = require('fs');

const app = express();
const port = 3000;

// Configure the storage engine for multer
const storage = multer.diskStorage({
 destination: (req, file, cb) => {
   cb(null, 'uploads/');
 },
 filename: (req, file, cb) => {
   cb(null, Date.now() + path.extname(file.originalname));
 },
});

const upload = multer({ storage });

// Define the endpoint for file uploads
app.post('/upload', upload.single('file'), (req, res) => {
 if (!req.file) {
   return res.status(400).send('No file uploaded');
 }

 // Check if the file is a dangerous type
 const allowedTypes = ['image/jpeg', 'image/png', 'application/pdf'];
 if (!allowedTypes.includes(req.file.mimetype)) {
   return res.status(400).send('File type not allowed');
 }

 // Check if the file size is within limits
 const maxSize = 10 * 1024 * 1024; // 10MB
 if (req.file.size > maxSize) {
   return res.status(400).send('File size exceeds the limit');
 }

 // Save the file to the server
 fs.writeFileSync(`uploads/${req.file.filename}`, req.file.buffer);

 res.status(200).send(`File uploaded successfully: ${req.file.filename}`);
});

app.listen(port, () => {
 console.log(`Server is running on port ${port}`);
});