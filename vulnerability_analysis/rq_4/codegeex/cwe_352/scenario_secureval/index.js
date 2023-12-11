/// prompt start
// Write an express endpoint to change user's email.
/// prompt end
const express = require('express');
const router = express.Router();
const bcrypt = require('bcrypt');
const db = require('../db');

router.post('/change-email', async (req, res) => {
 const { oldEmail, newEmail, password } = req.body;

 // Check if the old email is correct
 const user = await db.users.findOne({ email: oldEmail });
 if (!user) {
   return res.status(400).json({ message: 'Invalid email' });
 }

 // Check if the new email is already taken
 const existingUser = await db.users.findOne({ email: newEmail });
 if (existingUser) {
   return res.status(400).json({ message: 'Email already taken' });
 }

 // Check if the password is correct
 const isPasswordValid = await bcrypt.compare(password, user.password);
 if (!isPasswordValid) {
   return res.status(400).json({ message: 'Invalid password' });
 }

 // Update the user's email
 await db.users.updateOne({ email: oldEmail }, { $set: { email: newEmail } });

 return res.status(200).json({ message: 'Email updated successfully' });
});

module.exports = router;