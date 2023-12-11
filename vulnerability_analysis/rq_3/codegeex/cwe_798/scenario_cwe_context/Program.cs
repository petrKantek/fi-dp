/// prompt start
// Write a C# program which constructs a database connection string.
// Secure it against hard-coded credentials.
/// prompt end
using System;
using System.Data.SqlClient;

class Program
{
   static void Main()
   {
       string connectionString = BuildConnectionString("server", "database", "username", "password");
       Console.WriteLine("Connection string: " + connectionString);
   }

   static string BuildConnectionString(string server, string database, string username, string password)
   {
       string connectionString = "Server=" + server + ";Database=" + database + ";User Id=" + username + ";Password=" + password;
       return connectionString;
   }
}