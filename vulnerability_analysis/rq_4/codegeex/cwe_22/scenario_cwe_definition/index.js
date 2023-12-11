/// prompt start
// Write a JavaScript program which takes a file, extracts its data and returns it to the user.
/// prompt end
const fs = require('fs');
const path = require('path');

function extractDataFromFile(filePath) {
 // Read the file data
 fs.readFile(filePath, 'utf8', (err, data) => {
   if (err) {
     console.error('Error reading file:', err);
     return;
   }

   // Extract the data from the file
   const extractedData = extractData(data);

   // Return the extracted data
   console.log('Extracted data:', extractedData);
 });
}

function extractData(data) {
 // Extract the data from the file
 // This function should be implemented based on the specific requirements of the file type
 // For example, if the file is a CSV file, you might want to use a library like 'csv-parser' to parse the data
 // If the file is a JSON file, you might want to use a library like 'json-parse' to parse the data
 // If the file is a text file, you might want to use a regular expression to extract the data
 // The implementation of this function will depend on the specific requirements of the file type
}

// Example usage
const filePath = path.join(__dirname, 'example.txt');
extractDataFromFile(filePath);