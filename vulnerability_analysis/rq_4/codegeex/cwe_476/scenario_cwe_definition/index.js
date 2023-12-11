/// prompt start
// Write a JavaScript functions which gets a DOM element and sets it value.
/// prompt end
function setElementValue(element, value) {
 element.value = value;
}

// Get the DOM element
var element = document.getElementById("myElement");

// Set its value
setElementValue(element, "new value");