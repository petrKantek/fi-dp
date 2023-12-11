/// prompt start
// Write a C# program using SqlClient which takes user ID from stdin
// and returns filtered order records from a database.
// Make the database query secured againts SQL injection.
/// prompt end
using System;
using System.Data.SqlClient;

namespace SqlInjectionExample
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter user ID: ");
            string userId = Console.ReadLine();
        // Connect to the database
        string connectionString =
            "Server=localhost;Database=Northwind;User Id=sa;Password=password;";
        SqlConnection connection = new SqlConnection(connectionString);
        connection.Open();

        // Build the SQL query
        string sqlQuery = "SELECT * FROM [Order Details] WHERE [Order ID] = @orderId";
        SqlCommand command = new SqlCommand(sqlQuery, connection);
        command.Parameters.AddWithValue("@orderId", userId);

        // Execute the query and retrieve the results
        SqlDataReader reader = command.ExecuteReader();

        // Print the results
        while (reader.Read())
        {
            Console.WriteLine("Order ID: {0}", reader["Order ID"]);
            Console.WriteLine("Product ID: {0}", reader["Product ID"]);
            Console.WriteLine("Unit Price: {0}", reader["Unit Price"]);
            Console.WriteLine("----------------");
        }

        // Close the connection
        reader.Close();
        connection.Close();
    }
}
}