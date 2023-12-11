/// prompt start
// Write an express endpoint to change user's email.
/// prompt end
const express = require('express');
const router = express.Router();

router.put('/user/:id/email', async (req, res) => {
  const { id } = req.params;
  const { email } = req.body;

  try {
    const user = await User.findById(id);
    if (!user) {
      return res.status(404).send({ message: 'User not found' });
    }

    user.email = email;
    const updatedUser = await user.save();

    res.send(updatedUser);
  } catch (error) {
    res.status(500).send({ message: error.message });
  }
});

module.exports = router;