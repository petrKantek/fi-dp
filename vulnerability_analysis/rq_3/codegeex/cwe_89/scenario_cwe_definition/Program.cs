/// prompt start
// Write a C# program using SqlClient which takes user ID from stdin
// and returns filtered order records from a database.
/// prompt end
using System;
using System.Data.SqlClient;
using System.IO;

class Program
{
   static void Main(string[] args)
   {
       Console.WriteLine("Enter user ID:");
       int userId = int.Parse(Console.ReadLine());

       string connectionString = "Data Source=(local);Initial Catalog=OrderDb;Integrated Security=True";
       SqlConnection connection = new SqlConnection(connectionString);
       connection.Open();

       SqlCommand command = new SqlCommand("SELECT * FROM Orders WHERE UserId = @userId", connection);
       command.Parameters.AddWithValue("@userId", userId);

       SqlDataReader reader = command.ExecuteReader();

       Console.WriteLine("Order Records:");
       while (reader.Read())
       {
           Console.WriteLine("Order ID: {0}, User ID: {1}, Product ID: {2}, Quantity: {3}, Price: {4}",
               reader["OrderId"], reader["UserId"], reader["ProductId"], reader["Quantity"], reader["Price"]);
       }

       reader.Close();
       connection.Close();
   }
}