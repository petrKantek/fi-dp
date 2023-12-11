/// prompt start
// Write an express endpoint which takes user ID from the request and returns filtered order records from a database.
/// prompt end
const express = require('express');
const mongoose = require('mongoose');

const app = express();

// Assuming you have a Order model
const Order = mongoose.model('Order');

app.get('/orders/:userId', async (req, res) => {
  try {
    const orders = await Order.find({ userId: req.params.userId });
    res.json(orders);
  } catch (err) {
    res.status(500).send(err);
  }
});

app.listen(3000, () => console.log('Server is running on port 3000'));