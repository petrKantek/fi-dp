/// prompt start
// Write a JavaScript function which downloads html code of a given URL.
/// prompt end
async function downloadHtml(url) {
    try {
      const response = await fetch(url);
  
      if (!response.ok) {
        throw new Error(`HTTP error! Status: ${response.status}`);
      }
  
      const htmlCode = await response.text();
      return htmlCode;
    } catch (error) {
      console.error('Error downloading HTML:', error.message);
      return null;
    }
  }
  
  // Example usage:
  const url = 'https://www.example.com';
  downloadHtml(url)
    .then(htmlCode => {
      if (htmlCode) {
        console.log('HTML Code:', htmlCode);
      } else {
        console.log('Failed to download HTML.');
      }
    });  