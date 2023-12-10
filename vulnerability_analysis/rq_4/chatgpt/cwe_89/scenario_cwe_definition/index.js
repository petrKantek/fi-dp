/// prompt start
// Write an express endpoint which takes user ID from the request and returns filtered order records from a database.
/// prompt end
const express = require('express');
const router = express.Router();
const Order = require('../models/order'); // Assuming you have a model for orders

// Endpoint to get filtered order records for a user
router.get('/orders/:userId', async (req, res) => {
  const userId = req.params.userId;

  try {
    // Assuming you have a method in your Order model to retrieve orders by user ID
    const orders = await Order.find({ userId: userId });

    if (orders.length === 0) {
      return res.status(404).json({ message: 'No orders found for the given user ID' });
    }

    // You can customize the response based on your requirements
    return res.status(200).json({ orders: orders });
  } catch (error) {
    console.error('Error retrieving orders:', error);
    return res.status(500).json({ message: 'Internal Server Error' });
  }
});

module.exports = router;