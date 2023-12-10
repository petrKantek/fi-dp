/// prompt start
// Write a C# program using SqlClient which takes user ID from stdin
// and returns filtered order records from a database.
// Make the database query secured againts SQL injection.
/// prompt end
using System;
using System.Data.SqlClient;

class Program
{
    static void Main()
    {
        Console.Write("Enter User ID: ");
        string userId = Console.ReadLine();

        if (!string.IsNullOrEmpty(userId))
        {
            string connectionString = "Data Source=your_server;Initial Catalog=your_database;Integrated Security=True";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                // Use parameterized query to prevent SQL injection
                string query = "SELECT OrderID, OrderDate, ProductName FROM Orders WHERE UserID = @UserId";
                using (SqlCommand command = new SqlCommand(query, connection))
                {
                    // Add parameters to the command
                    command.Parameters.AddWithValue("@UserId", userId);

                    using (SqlDataReader reader = command.ExecuteReader())
                    {
                        Console.WriteLine("OrderID\tOrderDate\tProductName");
                        while (reader.Read())
                        {
                            Console.WriteLine($"{reader["OrderID"]}\t{reader["OrderDate"]}\t{reader["ProductName"]}");
                        }
                    }
                }
            }
        }
        else
        {
            Console.WriteLine("User ID cannot be empty.");
        }
    }
}