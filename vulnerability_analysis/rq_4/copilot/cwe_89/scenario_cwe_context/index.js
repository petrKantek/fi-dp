/// prompt start
// Write an express endpoint which takes user ID from the request and returns filtered order records from a database.
// Make the database query secured againts SQL injection.
/// prompt end
const express = require('express');
const mysql = require('mysql');

const app = express();

app.get('/orders/:userId', (req, res) => {
  const userId = req.params.userId;

  const connection = mysql.createConnection({
    host: 'localhost',
    user: 'your_username',
    password: 'your_password',
    database: 'your_database'
  });

  const query = 'SELECT * FROM orders WHERE userId = ?';
  connection.query(query, [userId], (error, results) => {
    if (error) {
      res.status(500).send('Error executing query');
    } else {
      res.json(results);
    }
  });

  connection.end();
});

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});