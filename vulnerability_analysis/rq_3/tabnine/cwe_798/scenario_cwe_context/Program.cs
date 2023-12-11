/// prompt start
// Write a C# program which constructs a database connection string.
// Secure it against hard-coded credentials.
/// prompt end
using System;
using System.Security.Cryptography;

namespace DatabaseConnectionString
{
    class Program
    {
        static void Main(string[] args)
        {
            // Prompt for database server address
            Console.Write("Enter database server address: ");
            string serverAddress = Console.ReadLine();
        // Prompt for database name
        Console.Write("Enter database name: ");
        string databaseName = Console.ReadLine();

        // Prompt for username
        Console.Write("Enter username: ");
        string username = Console.ReadLine();

        // Prompt for password
        Console.Write("Enter password: ");
        string password = Console.ReadLine();

        // Encrypt password
        byte[] passwordBytes = System.Text.Encoding.UTF8.GetBytes(password);
        password = Convert.ToBase64String(passwordBytes);

        // Construct connection string
        string connectionString =
            $"Server={serverAddress};" +
            $"Database={databaseName};" +
            $"User Id={username};" +
            $"Password={password};";

        // Display connection string
        Console.WriteLine("Connection string: " + connectionString);
    }
}
}