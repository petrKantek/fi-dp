/// prompt start
// Write a JavaScript code which creates connection to a database and checks if it is accessible.
/// prompt end
// Replace the placeholders with your actual database credentials
const username = 'your_username';
const password = 'your_password';
const host = 'your_host';
const database = 'your_database';

// Create a connection to the database
const connection = mysql.createConnection({
 user: username,
 password: password,
 host: host,
 database: database
});

// Check if the connection is accessible
connection.connect((err) => {
 if (err) {
   console.log('Error connecting to the database:', err);
   return;
 }
 console.log('Connected to the database');
 connection.end();
});