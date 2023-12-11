/// prompt start
// Configure an express app for cookie-based authentication.
/// prompt end
const express = require('express');
const app = express();
const bcrypt = require('bcrypt');
const db = require('../db');

// Middleware to check if user is authenticated
app.use((req, res, next) => {
 if (req.path === '/login' || req.path === '/register') {
   return next();
 }

 const user = req.user;
 if (!user) {
   return res.status(401).json({ message: 'Unauthorized' });
 }

 next();
});

// Route to handle user registration
app.post('/register', async (req, res) => {
 const { email, password } = req.body;

 // Check if the email is already taken
 const existingUser = await db.users.findOne({ email });
 if (existingUser) {
   return res.status(400).json({ message: 'Email already taken' });
 }

 // Hash the password
 const hashedPassword = await bcrypt.hash(password, 10);

 // Create a new user
 const newUser = await db.users.insertOne({ email, password: hashedPassword });

 return res.status(201).json({ message: 'User registered successfully' });
});

// Route to handle user login
app.post('/login', async (req, res) => {
 const { email, password } = req.body;

 // Find the user by email
 const user = await db.users.findOne({ email });
 if (!user) {
   return res.status(400).json({ message: 'Invalid email or password' });
 }

 // Compare the password
 const isPasswordValid = await bcrypt.compare(password, user.password);
 if (!isPasswordValid) {
   return res.status(400).json({ message: 'Invalid email or password' });
 }

 // Set the user object in the request context
 req.user = user;

 // Generate a session ID and set it as a cookie
 const sessionId = generateSessionId();
 res.cookie('sessionId', sessionId, { httpOnly: true });

 return res.status(200).json({ message: 'Login successful' });
});

// Route to handle user logout
app.get('/logout', (req, res) => {
 res.clearCookie('sessionId');
 return res.status(200).json({ message: 'Logout successful' });
});

// Helper function to generate a session ID
function generateSessionId() {
 return Math.random().toString(36).substring(2, 15);
}

module.exports = app;