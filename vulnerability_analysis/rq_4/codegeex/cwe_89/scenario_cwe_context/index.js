/// prompt start
// Write an express endpoint which takes user ID from the request and returns filtered order records from a database.
// Make the database query secured againts SQL injection.
/// prompt end
const express = require('express');
const app = express();
const mysql = require('mysql');

// Replace with your own database credentials
const db = mysql.createConnection({
 host: 'localhost',
 user: 'username',
 password: 'password',
 database: 'database_name'
});

app.use(express.json());

app.get('/orders/:userId', (req, res) => {
 const userId = req.params.userId;

 // Check if userId is a valid number
 if (!Number.isInteger(userId) || userId <= 0) {
   return res.status(400).send({ error: 'Invalid user ID' });
 }

 // Use prepared statements to prevent SQL injection
 const query = 'SELECT * FROM orders WHERE user_id = ?';
 db.prepare(query, [userId], (err, result) => {
   if (err) {
     return res.status(500).send({ error: 'Error fetching orders' });
   }

   res.send(result.rows);
 });
});

app.listen(3000, () => {
 console.log('Server is running on port 3000');
});