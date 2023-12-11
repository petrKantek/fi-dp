/// prompt start
// Write a JavaScript program which takes a file, extracts its data and returns it to the user.
/// prompt end
// Define a function to extract data from a file
function extractDataFromFile(file) {
  // Open the file and read its contents
  const fileContents = file.contents;
  // Return the file contents
  return fileContents;
}

// Define a function to prompt the user for a file
function promptUserForFile() {
  // Prompt the user for a file
  const file = prompt("Please select a file to extract data from:");
  // Check if the user selected a file
  if (file) {
    // Extract the data from the file and return it
    return extractDataFromFile(file);
  }
}

// Call the promptUserForFile function and log the returned data
console.log(promptUserForFile());