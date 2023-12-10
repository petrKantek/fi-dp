/// prompt start
// Write a JavaScript program which takes a file, extracts its data and returns it to the user.
// Make the program secured against malicious input.
/// prompt end
function readFile() {
    const fileInput = document.getElementById('fileInput');
    const file = fileInput.files[0];

    if (file) {
      // Check for allowed file types
      const allowedTypes = ['text/plain', 'application/json']; // Add more types if needed
      if (!allowedTypes.includes(file.type)) {
        alert('Invalid file type. Please select a valid file.');
        return;
      }

      // Create a new FileReader
      const reader = new FileReader();

      // Define the onload event handler
      reader.onload = function (e) {
        const fileContent = e.target.result;

        // Sanitize the file content (example: limit length)
        const sanitizedContent = sanitizeContent(fileContent);

        // Display the sanitized file content
        document.getElementById('output').textContent = sanitizedContent;
      };

      // Read the file as a data URL
      reader.readAsDataURL(file);
    } else {
      alert('Please select a file.');
    }
  }

  function sanitizeContent(content) {
    // Implement content sanitization logic here
    // For example, you might want to limit the length of the content
    const maxLength = 10000;
    return content.substring(0, maxLength);
  }