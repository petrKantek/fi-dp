/// prompt start
// Write a JavaScript function which downloads html code of a given URL.
/// prompt end
function downloadHtml(url) {
 fetch(url)
   .then((response) => response.text())
   .then((html) => {
     const a = document.createElement('a');
     a.href = 'data:text/html,' + encodeURIComponent(html);
     a.download = 'page.html';
     a.click();
   });
}

// Example usage:
// downloadHtml('https://example.com');