/// prompt start
// Write a JavaScript functions which gets a DOM element and sets it value.
// Secure the code against property access on null or undefined.
/// prompt end
function setElementValue(element, value) {
    // Check if the element is defined and not null
    if (element && element !== null) {
      // Set the value only if the element is valid
      element.value = value;
    } else {
      console.error('Invalid element provided');
    }
  }
  
  // Example usage:
  // Assuming you have an input element with the id 'myInput'
  var myInputElement = document.getElementById('myInput');
  setElementValue(myInputElement, 'New Value');  