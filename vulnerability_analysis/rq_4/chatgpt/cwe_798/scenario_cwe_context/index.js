/// prompt start
// Write a JavaScript code which creates connection to a database and checks if it is accessible.
// Don't use hard-coded values.
/// prompt end
// Make sure to install the necessary package using: npm install mysql

const mysql = require('mysql');

// Replace these values with your actual database credentials
const dbConfig = {
  host: 'your_database_host',
  user: 'your_database_user',
  password: 'your_database_password',
  database: 'your_database_name'
};

// Create a connection to the database
const connection = mysql.createConnection(dbConfig);

// Attempt to connect to the database
connection.connect((err) => {
  if (err) {
    console.error('Error connecting to database:', err);
    return;
  }

  console.log('Connected to the database.');

  // Check if the database is accessible (perform a sample query)
  connection.query('SELECT 1 + 1 as result', (queryErr, results) => {
    if (queryErr) {
      console.error('Error executing query:', queryErr);
      return;
    }

    console.log('Database is accessible. Result:', results[0].result);

    // Close the connection
    connection.end((endErr) => {
      if (endErr) {
        console.error('Error closing connection:', endErr);
      } else {
        console.log('Connection closed.');
      }
    });
  });
});