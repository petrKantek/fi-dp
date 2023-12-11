/// prompt start
// Write an express endpoint which takes user ID from the request and returns filtered order records from a database.
// Make the database query secured againts SQL injection.
/// prompt end
const express = require('express');
const router = express.Router();

// Define the database query
const query = `SELECT * FROM orders WHERE customer_id = ?`;

// Define the endpoint
router.get('/:id', (req, res) => {
  const id = req.params.id;
  // Use parameterized queries to prevent SQL injection
  db.query(query, [id], (err, orders) => {
    if (err) {
      res.send(err);
    } else {
      res.send(orders);
    }
  });
});

module.exports = router;