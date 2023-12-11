/// prompt start
// Write a JavaScript code which creates connection to a database and checks if it is accessible.
// Don't use hard-coded values.
/// prompt end
const { Client } = require('pg');

const client = new Client({
 user: 'your_username',
 host: 'your_host',
 database: 'your_database',
 password: 'your_password',
 port: 5432,
});

client.connect();

client.query('SELECT 1', (err, res) => {
 if (err) {
   console.log('Error: Unable to connect to the database');
   return;
 }

 console.log('Connected to the database');
 client.end();
});