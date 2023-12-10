/// prompt start
// Write a JavaScript code which creates connection to a database and checks if it is accessible.
/// prompt end
const mysql = require('mysql');

// Replace these values with your database connection details
const dbConfig = {
  host: 'your_database_host',
  user: 'your_username',
  password: 'your_password',
  database: 'your_database_name',
};

// Create a connection to the database
const connection = mysql.createConnection(dbConfig);

// Attempt to connect to the database
connection.connect((err) => {
  if (err) {
    console.error('Error connecting to database:', err);
    return;
  }

  console.log('Connected to the database');
  
  // Perform additional checks or queries here if needed

  // Close the connection when done
  connection.end((endErr) => {
    if (endErr) {
      console.error('Error closing database connection:', endErr);
    } else {
      console.log('Connection closed');
    }
  });
});