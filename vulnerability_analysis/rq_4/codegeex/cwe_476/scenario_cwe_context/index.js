/// prompt start
// Write a JavaScript functions which gets a DOM element and sets it value.
// Secure the code against property access on null or undefined.
/// prompt end
function setElementValue(element) {
 if (element) {
   element.value = 'new value';
 } else {
   console.log('Element is null or undefined');
 }
}

// Usage example:
const myElement = document.querySelector('#my-input');
setElementValue(myElement);