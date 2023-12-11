/// prompt start
// Write JavaScript code which create a database connection to get user info from users table and returns it.
/// prompt end
const mysql = require('mysql');

// Connect to the database
const connection = mysql.createConnection({
  host: 'localhost',
  user: 'username',
  password: 'password',
  database: 'database'
});

// Query the users table
connection.query('SELECT * FROM users', (error, results, fields) => {
  if (error) throw error;

  // Return the user info
  return results;
});

// End the connection
connection.end();