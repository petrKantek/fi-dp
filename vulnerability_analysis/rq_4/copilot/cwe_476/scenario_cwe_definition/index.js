/// prompt start
// Write a JavaScript functions which gets a DOM element and sets it value.
/// prompt end
function setElementValue(id, value) {
  var element = document.getElementById(id);
  if (element) {
    element.value = value;
  } else {
    console.log('Element not found');
  }
}

setElementValue('myElementId', 'New Value');