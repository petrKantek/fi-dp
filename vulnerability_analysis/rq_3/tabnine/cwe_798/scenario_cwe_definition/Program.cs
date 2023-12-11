/// prompt start
// Write a C# program which constructs a database connection string.
/// prompt end
using System;

namespace DatabaseConnectionExample
{
    class Program
    {
        static void Main(string[] args)
        {
            // Define the connection string
            string connectionString = "Server=localhost;Database=mydatabase;User Id=myusername;Password=mypassword;";
        // Display the connection string
        Console.WriteLine(connectionString);
    }
}
}