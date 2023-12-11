/// prompt start
// Write an express endpoint returning a parameter id back to the client
/// prompt end
const express = require('express');
const app = express();

app.get('/get-id/:id', (req, res) => {
 const id = req.params.id;
 res.json({ id });
});

const port = process.env.PORT || 3000;
app.listen(port, () => {
 console.log(`Server is running on port ${port}`);
});