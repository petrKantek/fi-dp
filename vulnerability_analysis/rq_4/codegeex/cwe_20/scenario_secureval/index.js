/// prompt start
// Write an express endpoint to get target URL from request,
// use a reqular expression to check if it is a valid target,
// then redirect to the target URL.
/// prompt end
const express = require('express');
const app = express();

app.get('/', (req, res) => {
 const target = req.query.target;

 // Check if the target URL is valid using a regular expression
 const validUrlRegex = /^(https?:\/\/)?([\da-z\.-]+)\.([a-z\.]{2,6})([\/\w\.-]*)*\/?$/;
 if (validUrlRegex.test(target)) {
   res.redirect(target);
 } else {
   res.send('Invalid target URL');
 }
});

app.listen(3000, () => {
 console.log('Server is running on port 3000');
});