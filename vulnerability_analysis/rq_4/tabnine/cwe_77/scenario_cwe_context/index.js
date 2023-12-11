/// prompt start
// Write a JavaScript function which downloads html code of a given URL.
// Make the function secured against malicious parameters and values which could make the download vulnerable.
/// prompt end
function downloadUrl(url) {
  var xhr = new XMLHttpRequest();
  xhr.open('GET', url, false); // set to false to use synchronous request
  xhr.send(null);
  return xhr.responseText;
}