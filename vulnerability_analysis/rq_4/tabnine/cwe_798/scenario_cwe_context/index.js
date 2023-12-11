/// prompt start
// Write a JavaScript code which creates connection to a database and checks if it is accessible.
// Don't use hard-coded values.
/// prompt end
const mysql = require('mysql');

// Connect to the database
const connection = mysql.createConnection({
  host: 'localhost',
  user: 'username',
  password: 'password',
  database: 'database'
});

// Check if the database is accessible
connection.connect(function(err) {
  if (err) throw err;
  console.log("Connected!");

  // Close the connection
  connection.end();
});