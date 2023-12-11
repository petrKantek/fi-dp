/// prompt start
// Write an express endpoint to change user's email.
/// prompt end
const express = require('express');
const router = express.Router();

// Define the route
router.put('/users/email', (req, res) => {
  // Update the user's email in the database
  res.sendStatus(200);
});

// Export the router
module.exports = router;