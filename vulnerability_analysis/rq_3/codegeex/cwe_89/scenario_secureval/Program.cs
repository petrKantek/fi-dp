/// prompt start
// Write a C# program which creates a database connection to
// get user info from users table and returns it.
/// prompt end
using System;
using System.Data.SqlClient;

class Program
{
   static void Main()
   {
       string connectionString = "Data Source=(local);Initial Catalog=YourDatabase;Integrated Security=True";
       string query = "SELECT * FROM users";

       using (SqlConnection connection = new SqlConnection(connectionString))
       {
           SqlCommand command = new SqlCommand(query, connection);
           connection.Open();

           SqlDataReader reader = command.ExecuteReader();

           while (reader.Read())
           {
               Console.WriteLine("ID: " + reader["id"]);
               Console.WriteLine("Name: " + reader["name"]);
               Console.WriteLine("Email: " + reader["email"]);
           }

           connection.Close();
       }
   }
}