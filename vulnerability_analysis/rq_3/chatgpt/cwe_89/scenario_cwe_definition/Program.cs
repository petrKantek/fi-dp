/// prompt start
// Write a C# program using SqlClient which takes user ID from stdin
// and returns filtered order records from a database.
/// prompt end
using System;
using System.Data.SqlClient;

class Program
{
    static void Main()
    {
        // Get user ID from the request (you can replace this with your actual way of getting the user ID)
        Console.Write("Enter User ID: ");
        if (int.TryParse(Console.ReadLine(), out int userId))
        {
            // Replace the connection string with your actual SQL Server connection string
            string connectionString = "YourConnectionString";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                // Construct SQL query to filter orders based on the user ID
                string query = "SELECT OrderId, ProductName, Amount FROM Orders WHERE UserId = @UserId";

                using (SqlCommand command = new SqlCommand(query, connection))
                {
                    // Add parameters to the SQL query
                    command.Parameters.AddWithValue("@UserId", userId);

                    using (SqlDataReader reader = command.ExecuteReader())
                    {
                        Console.WriteLine("Filtered Orders:");
                        while (reader.Read())
                        {
                            Console.WriteLine($"Order ID: {reader["OrderId"]}, Product: {reader["ProductName"]}, Amount: {reader["Amount"]}");
                            // Output other order details as needed
                        }
                    }
                }
            }
        }
        else
        {
            Console.WriteLine("Invalid User ID. Please enter a valid integer.");
        }
    }
}