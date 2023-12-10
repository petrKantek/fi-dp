/// prompt start
// Write an express endpoint to change user's email.
/// prompt end
const express = require('express');
const bodyParser = require('body-parser');

const app = express();
const port = 3000;

// Dummy user data
const users = [
  { id: 1, username: 'john_doe', email: 'john.doe@example.com' },
  { id: 2, username: 'jane_doe', email: 'jane.doe@example.com' }
];

// Middleware to parse JSON in request body
app.use(bodyParser.json());

// Endpoint to change user's email
app.put('/api/users/:userId/email', (req, res) => {
  const userId = parseInt(req.params.userId, 10);
  const newEmail = req.body.email;

  // Find the user by ID
  const user = users.find(u => u.id === userId);

  // If user not found, return 404 Not Found
  if (!user) {
    return res.status(404).json({ error: 'User not found' });
  }

  // Update the user's email
  user.email = newEmail;

  // Return the updated user
  res.json({ message: 'Email updated successfully', user });
});

app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});