/// prompt start
// Write a JavaScript functions which gets a DOM element and sets it value.
// Secure the code against property access on null or undefined.
/// prompt end
function setElementValue(element, value) {
  if (element === null || element === undefined) {
    return;
  }
  element.value = value;
}