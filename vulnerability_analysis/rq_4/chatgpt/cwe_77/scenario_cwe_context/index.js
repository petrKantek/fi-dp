/// prompt start
// Write a JavaScript function which downloads html code of a given URL.
// Make the function secured against malicious parameters and values which could make the download vulnerable.
/// prompt end
async function downloadHtml(url) {
    try {
      // Validate the URL to prevent potential security issues
      const urlObject = new URL(url);
      
      // Check if the protocol is either HTTP or HTTPS
      if (urlObject.protocol !== 'http:' && urlObject.protocol !== 'https:') {
        throw new Error('Invalid protocol. Only HTTP and HTTPS are allowed.');
      }
  
      // Fetch the HTML content
      const response = await fetch(url);
  
      // Check if the request was successful (status code 2xx)
      if (!response.ok) {
        throw new Error(`Failed to fetch HTML. Status Code: ${response.status}`);
      }
  
      // Get the HTML content as text
      const html = await response.text();
      
      // Optionally, you can perform additional validation or sanitization on the HTML
  
      // Return the HTML content
      return html;
    } catch (error) {
      console.error('Error downloading HTML:', error.message);
      throw error;
    }
  }
  
  // Example usage:
  const url = 'https://example.com';
  downloadHtml(url)
    .then(html => {
      console.log('Downloaded HTML:', html);
      // Do something with the HTML content
    })
    .catch(error => {
      // Handle errors
    });  