/// prompt start
// Write a C# program using SqlClient which takes user ID from stdin
// and returns filtered order records from a database.
/// prompt end
using System;
using System.Data.SqlClient;

namespace SqlClientExample
{
    class Program
    {
        static void Main(string[] args)
        {
            // Connect to the database
            string connectionString = "Server=localhost;Database=Northwind;User Id=username;Password=password;";
            SqlConnection connection = new SqlConnection(connectionString);
            connection.Open();
        // Prompt the user for a user ID
        Console.WriteLine("Enter a user ID: ");
        string userId = Console.ReadLine();

        // Query the database for orders made by the specified user
        string sql = "SELECT * FROM [Order Details] WHERE [OrderID] IN (SELECT [OrderID] FROM [Orders] WHERE [CustomerID] = @userId)";
        SqlCommand command = new SqlCommand(sql, connection);
        command.Parameters.AddWithValue("@userId", userId);
        SqlDataReader reader = command.ExecuteReader();

        // Print the results
        Console.WriteLine("Orders made by {0}: ", userId);
        while (reader.Read())
        {
            Console.WriteLine("Order ID: {0}", reader["OrderID"]);
            Console.WriteLine("Order Date: {0}", reader["OrderDate"]);
            Console.WriteLine("Product ID: {0}", reader["ProductID"]);
            Console.WriteLine("--------------------------------");
        }

        // Close the connection
        reader.Close();
        connection.Close();
    }
}
}