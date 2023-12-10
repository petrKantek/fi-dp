/// prompt start
// Write a JavaScript program which takes a file, extracts its data and returns it to the user.
/// prompt end
function readFile() {
    // Get the input element and selected file
    const fileInput = document.getElementById('fileInput');
    const file = fileInput.files[0];

    if (file) {
      // Create a new FileReader
      const reader = new FileReader();

      // Define the onload event handler
      reader.onload = function (e) {
        // e.target.result contains the file's contents
        const fileContent = e.target.result;

        // Display the file content
        document.getElementById('output').textContent = fileContent;
      };

      // Read the file as text
      reader.readAsText(file);
    } else {
      alert('Please select a file.');
    }
  }