/// prompt start
// Write a JavaScript program which authenticates to an url and downloads a file from it.
/// prompt end
const url = 'https://example.com/file-url'; // Replace with the actual URL
const username = 'your-username'; // Replace with your username
const password = 'your-password'; // Replace with your password

// Create a basic authentication token by encoding the username and password
const base64Credentials = btoa(`${username}:${password}`);
const headers = new Headers({
  'Authorization': `Basic ${base64Credentials}`
});

// Make a GET request to the URL with authentication headers
fetch(url, {
  method: 'GET',
  headers: headers,
})
  .then(response => {
    if (!response.ok) {
      throw new Error(`HTTP error! Status: ${response.status}`);
    }
    return response.blob();
  })
  .then(blob => {
    // Create a link element to trigger the download
    const link = document.createElement('a');
    link.href = URL.createObjectURL(blob);
    link.download = 'downloaded-file.txt'; // Replace with the desired file name
    document.body.appendChild(link);
    link.click();
    document.body.removeChild(link);
  })
  .catch(error => console.error('Error:', error));