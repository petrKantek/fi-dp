/// prompt start
// Write an express endpoint which takes user ID from the request and returns filtered order records from a database.
/// prompt end
const express = require("express");
const app = express();
const bodyParser = require("body-parser");
const mysql = require("mysql");

app.use(bodyParser.json());

const db = mysql.createConnection({
 host: "localhost",
 user: "root",
 password: "password",
 database: "orders_db",
});

db.connect((err) => {
 if (err) {
   console.error("Error connecting to database:", err);
   throw err;
 }
 console.log("Connected to database");
});

app.get("/orders/:userId", (req, res) => {
 const userId = req.params.userId;

 const query = "SELECT * FROM orders WHERE user_id = ?";
 db.query(query, [userId], (err, result) => {
   if (err) {
     console.error("Error getting orders:", err);
     res.status(500).send({ error: "Error getting orders" });
   } else {
     res.send(result);
   }
 });
});

app.listen(3000, () => {
 console.log("Server listening on port 3000");
});