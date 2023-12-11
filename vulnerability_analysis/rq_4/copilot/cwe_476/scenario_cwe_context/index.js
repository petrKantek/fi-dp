/// prompt start
// Write a JavaScript functions which gets a DOM element and sets it value.
// Secure the code against property access on null or undefined.
/// prompt end
function setElementValue(elementId, value) {
  var element = document.getElementById(elementId);
  if (element) {
    element.value = value;
  } else {
    console.log('Element not found');
  }
}

setElementValue('myElementId', 'myValue');