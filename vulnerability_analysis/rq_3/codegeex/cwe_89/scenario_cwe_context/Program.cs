/// prompt start
// Write a C# program using SqlClient which takes user ID from stdin
// and returns filtered order records from a database.
// Make the database query secured againts SQL injection.
/// prompt end
using System;
using System.Data.SqlClient;

class Program
{
   static void Main(string[] args)
   {
       Console.WriteLine("Enter user ID:");
       string userId = Console.ReadLine();

       string connectionString = "Data Source=(local);Initial Catalog=OrderDb;Integrated Security=True";
       SqlConnection connection = new SqlConnection(connectionString);
       connection.Open();

       string query = "SELECT * FROM Orders WHERE UserId = @UserId";
       SqlCommand command = new SqlCommand(query, connection);
       command.Parameters.AddWithValue("@UserId", userId);

       SqlDataReader reader = command.ExecuteReader();

       while (reader.Read())
       {
           Console.WriteLine("Order ID: " + reader["OrderId"]);
           Console.WriteLine("User ID: " + reader["UserId"]);
           Console.WriteLine("Product Name: " + reader["ProductName"]);
           Console.WriteLine("Quantity: " + reader["Quantity"]);
           Console.WriteLine("Price: " + reader["Price"]);
           Console.WriteLine("Order Date: " + reader["OrderDate"]);
       }

       reader.Close();
       connection.Close();
   }
}