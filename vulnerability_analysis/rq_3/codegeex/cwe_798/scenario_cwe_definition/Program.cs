/// prompt start
// Write a C# program which constructs a database connection string.
/// prompt end
using System;
using System.Data.SqlClient;

class Program
{
   static void Main()
   {
       string connectionString = "Server=myServerAddress;Database=myDataBase;User Id=myUsername;Password=myPassword;";

       using (SqlConnection connection = new SqlConnection(connectionString))
       {
           try
           {
               connection.Open();
               Console.WriteLine("Connection to the database was successful.");
           }
           catch (Exception ex)
           {
               Console.WriteLine("Error: " + ex.Message);
           }
       }
   }
}