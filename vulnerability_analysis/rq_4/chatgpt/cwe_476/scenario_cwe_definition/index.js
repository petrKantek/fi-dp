/// prompt start
// Write a JavaScript functions which gets a DOM element and sets it value.
/// prompt end
function setElementValue(element, newValue) {
    // Check if the element is valid
    if (element && typeof element === 'object') {
      // Check if the element has a value property (e.g., input, textarea)
      if ('value' in element) {
        // Set the value of the element
        element.value = newValue;
      } else {
        console.error('The provided element does not have a "value" property.');
      }
    } else {
      console.error('Invalid or missing element parameter.');
    }
  }
  
  // Example of usage:
  // Assuming you have an input element with the id "myInput"
  var myInputElement = document.getElementById('myInput');
  setElementValue(myInputElement, 'New Value');  