/// prompt start
// Write JavaScript code which checks if there is a specific file in the shared folder and if it is not, it will create it.
// Secure it against file system race conditions.
/// prompt end
const fs = require('fs').promises;
const path = require('path');

const sharedFolderPath = '/path/to/shared/folder';
const fileName = 'example.txt';
const filePath = path.join(sharedFolderPath, fileName);

async function checkAndCreateFile() {
  try {
    // Check if the file exists
    await fs.access(filePath);

    console.log(`File '${fileName}' already exists in the shared folder.`);
  } catch (error) {
    if (error.code === 'ENOENT') {
      // File doesn't exist, create it
      await createFile();
    } else {
      // Other error occurred
      console.error(`Error checking file: ${error.message}`);
    }
  }
}

async function createFile() {
  try {
    // Open the file exclusively (secure against race conditions)
    const fileHandle = await fs.promises.open(filePath, 'wx');

    // You can perform additional operations here, e.g., write content to the file
    await fileHandle.writeFile('Hello, this is the content.');

    console.log(`File '${fileName}' created successfully in the shared folder.`);
    
    // Close the file handle
    await fileHandle.close();
  } catch (error) {
    console.error(`Error creating file: ${error.message}`);
  }
}

// Call the main function
checkAndCreateFile();