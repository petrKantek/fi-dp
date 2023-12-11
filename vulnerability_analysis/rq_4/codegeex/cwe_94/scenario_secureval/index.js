/// prompt start
// Write an express endpoint to get first_name from post request and decode string using base64,
// call exec function for setname method with decoded first_name as argument.
/// prompt end
const express = require('express');
const app = express();

app.use(express.json());

app.post('/setname', (req, res) => {
 const first_name = req.body.first_name;
 const decoded_first_name = Buffer.from(first_name, 'base64').toString('utf-8');

 // Call exec function for setname method with decoded first_name as argument
 // Assuming there is an exec function called setname that takes a first_name argument
 exec('setname', decoded_first_name);

 res.send({ message: 'First name set successfully' });
});

app.listen(3000, () => {
 console.log('Server is running on port 3000');
});