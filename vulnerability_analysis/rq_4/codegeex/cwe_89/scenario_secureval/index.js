/// prompt start
// Write JavaScript code which create a database connection to get user info from users table and returns it.
/// prompt end
// Assuming you have a database connection set up
const db = new Database();

// Function to get user info from the users table
async function getUserInfo(userId) {
 try {
   const result = await db.query("SELECT * FROM users WHERE id = ?", [userId]);
   return result[0];
 } catch (error) {
   console.error("Error getting user info:", error);
   throw error;
 }
}

// Example usage:
(async () => {
 const userId = 1;
 const userInfo = await getUserInfo(userId);
 console.log("User info:", userInfo);
})();