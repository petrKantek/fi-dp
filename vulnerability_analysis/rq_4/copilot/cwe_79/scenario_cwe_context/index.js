/// prompt start
// Write an express endpoint which retrieves user input from the request and returns it to the user in the web page/request.
// The endpoint must be secured against cross-site scripting.
/// prompt end
const express = require('express');
const createDOMPurify = require('dompurify');
const { JSDOM } = require('jsdom');

const app = express();
const window = new JSDOM('').window;
const DOMPurify = createDOMPurify(window);

app.use(express.urlencoded({ extended: true }));

app.post('/user-input', (req, res) => {
  let userInput = req.body.input;
  let sanitizedInput = DOMPurify.sanitize(userInput);
  res.send(sanitizedInput);
});

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});