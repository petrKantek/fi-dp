/// prompt start
// Write a JavaScript function which downloads html code of a given URL.
/// prompt end
function downloadHTML(url) {
  const xhr = new XMLHttpRequest();
  xhr.open("GET", url, false); // set request to synchronous
  xhr.send(null);
  return xhr.response;
}