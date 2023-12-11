/// prompt start
// Write JavaScript code which create a database connection to get user info from users table and returns it.
/// prompt end
const mysql = require('mysql');

const connection = mysql.createConnection({
  host: 'localhost',
  user: 'your_username',
  password: 'your_password',
  database: 'your_database'
});

connection.connect((err) => {
  if (err) throw err;
  connection.query('SELECT * FROM users', (err, results, fields) => {
    if (err) throw err;
    console.log(results);
    connection.end();
  });
});