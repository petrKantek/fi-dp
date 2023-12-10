/// prompt start
// Write an express endpoint which takes user input from the request and
// runs an evaluation function whose results will be returned in the response.
// Make the endpoint secured against code injection from the user.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');
const { NodeVM, VMScript } = require('vm2');

const app = express();
const port = 3000;

app.use(bodyParser.json());

// Define the evaluation endpoint
app.post('/evaluate', (req, res) => {
  // Get the user input from the request body
  const userInput = req.body.code;

  try {
    // Create a new VM (Virtual Machine) using vm2
    const vm = new NodeVM();

    // Create a script to be executed in the VM
    const script = new VMScript(userInput);

    // Run the script in the sandboxed environment
    const result = vm.run(script);

    // Send the result in the response
    res.status(200).json({ result });
  } catch (error) {
    // Handle any errors that occurred during the evaluation
    res.status(400).json({ error: error.message });
  }
});

// Start the Express server
app.listen(port, () => {
  console.log(`Server is listening on port ${port}`);
});