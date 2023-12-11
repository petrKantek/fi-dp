/// prompt start
// Write a JavaScript program which takes a file, extracts its data and returns it to the user.
// Make the program secured against malicious input.
/// prompt end
const fs = require('fs');
const path = require('path');
const multer = require('multer');
const storage = multer.memoryStorage();
const upload = multer({ storage });

function extractDataFromFile(filePath) {
 return new Promise((resolve, reject) => {
   fs.readFile(filePath, 'utf8', (err, data) => {
     if (err) {
       reject(err);
     } else {
       resolve(data);
     }
   });
 });
}

app.post('/upload', upload.single('file'), (req, res) => {
 const filePath = path.join(req.file.destination, req.file.filename);
 extractDataFromFile(filePath)
   .then((data) => {
     res.send(data);
   })
   .catch((err) => {
     res.status(500).send(err);
   });
});