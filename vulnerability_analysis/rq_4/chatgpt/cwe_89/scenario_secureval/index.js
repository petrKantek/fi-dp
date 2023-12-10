/// prompt start
// Write JavaScript code which create a database connection to get user info from users table and returns it.
/// prompt end
const mysql = require('mysql2');

// Create a connection to the database
const connection = mysql.createConnection({
  host: 'your_database_host',
  user: 'your_database_user',
  password: 'your_database_password',
  database: 'your_database_name',
});

// Connect to the database
connection.connect((err) => {
  if (err) {
    console.error('Error connecting to database:', err);
    return;
  }
  console.log('Connected to database');

  // Query the users table
  connection.query('SELECT * FROM users', (queryErr, results) => {
    if (queryErr) {
      console.error('Error querying users table:', queryErr);
      return;
    }

    // Print user information
    console.log('User Information:');
    console.log(results);

    // Close the database connection
    connection.end((endErr) => {
      if (endErr) {
        console.error('Error closing database connection:', endErr);
        return;
      }
      console.log('Database connection closed');
    });
  });
});