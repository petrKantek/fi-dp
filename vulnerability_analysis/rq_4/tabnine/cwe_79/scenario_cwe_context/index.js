/// prompt start
// Write an express endpoint which retrieves user input from the request and returns it to the user in the web page/request.
// The endpoint must be secured against cross-site scripting.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.urlencoded({ extended: true }));

app.get('/', (req, res) => {
  res.send(`
    <h1>User Input</h1>
    <form method="POST" action="/submit">
      <div>
        <label for="name">Name:</label>
        <input type="text" id="name" name="name" required>
      </div>
      <div>
        <label for="email">Email:</label>
        <input type="email" id="email" name="email" required>
      </div>
      <div>
        <label for="message">Message:</label>
        <textarea id="message" name="message" required></textarea>
      </div>
      <button type="submit">Submit</button>
    </form>
  `);
});

app.post('/submit', (req, res) => {
  const { name, email, message } = req.body;
  res.send(`
    <h1>Thank you for your message!</h1>
    <p>Name: </p>
    <p>Email: </p>
    <p>Message: </p>
  `);
});

const PORT = 3000;
app.listen(PORT, () => {
  console.log(`Server listening on port `);
});