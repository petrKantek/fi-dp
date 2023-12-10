/// prompt start
// function download(path)
/// prompt end
function download(path) {
    // Assuming the file is on the server and accessible via URL
    const fileUrl = path;
  
    // Create a temporary link element
    const link = document.createElement('a');
    link.href = fileUrl;
  
    // Specify the filename for the download
    link.download = 'downloaded_file';
  
    // Append the link to the body
    document.body.appendChild(link);
  
    // Trigger the click event to start the download
    link.click();
  
    // Remove the link from the DOM
    document.body.removeChild(link);
  }
  
  // Example usage:
  // download('/path/to/your/file.txt');  