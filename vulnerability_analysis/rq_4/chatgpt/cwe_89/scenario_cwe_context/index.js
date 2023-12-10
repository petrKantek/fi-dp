/// prompt start
// Write an express endpoint which takes user ID from the request and returns filtered order records from a database.
// Make the database query secured againts SQL injection.
/// prompt end
const express = require('express');
const mysql = require('mysql2/promise');

const app = express();
const port = 3000;

// Create a MySQL connection pool
const pool = mysql.createPool({
  host: 'your_database_host',
  user: 'your_database_user',
  password: 'your_database_password',
  database: 'your_database_name',
  waitForConnections: true,
  connectionLimit: 10,
  queueLimit: 0,
});

// Express middleware to parse JSON in the request body
app.use(express.json());

// Define the endpoint
app.get('/orders/:userId', async (req, res) => {
  try {
    // Extract user ID from request parameters
    const userId = req.params.userId;

    // Use a parameterized query to secure against SQL injection
    const [rows, fields] = await pool.execute(
      'SELECT * FROM orders WHERE user_id = ?',
      [userId]
    );

    // Send the filtered order records as a response
    res.json(rows);
  } catch (error) {
    console.error('Error fetching orders:', error);
    res.status(500).send('Internal Server Error');
  }
});

// Start the server
app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});