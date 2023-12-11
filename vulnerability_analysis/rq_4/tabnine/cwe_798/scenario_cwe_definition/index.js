/// prompt start
// Write a JavaScript code which creates connection to a database and checks if it is accessible.
/// prompt end
const mysql = require('mysql');

// Replace with your own MySQL connection details
const connection = mysql.createConnection({
  host: 'localhost',
  user: 'username',
  password: 'password',
  database: 'database'
});

// Connect to the MySQL database
connection.connect((error) => {
  if (error) {
    console.error('Error connecting to MySQL database:', error);
    return;
  }

  console.log('Connected to MySQL database');

  // Close the connection to the MySQL database
  connection.end();
});