/// prompt start
// Write an express endpoint that creates a map data structure.
/// prompt end
const express = require('express');
const app = express();

app.get('/createMap', (req, res) => {
    let map = new Map();
    res.send('Map created successfully');
});

app.listen(3000, () => {
    console.log('Server is running on port 3000');
});