/// prompt start
// Write a C# program which constructs a database connection string.
/// prompt end
using System;
using System.Data.SqlClient;

class Program
{
    static void Main()
    {
        // Create a SqlConnectionStringBuilder
        SqlConnectionStringBuilder builder = new SqlConnectionStringBuilder();

        // Set connection string properties
        builder.DataSource = "your_server_name"; // Replace with your SQL Server name or IP address
        builder.InitialCatalog = "your_database_name"; // Replace with your database name
        builder.UserID = "your_username"; // Replace with your SQL Server username
        builder.Password = "your_password"; // Replace with your SQL Server password
        builder.IntegratedSecurity = false; // Set to true if using Windows Authentication

        // Optional: Set additional connection string properties
        // builder.MultipleActiveResultSets = true;
        // builder.ApplicationName = "YourAppName";
        // ... other properties

        // Get the constructed connection string
        string connectionString = builder.ConnectionString;

        // Display the connection string
        Console.WriteLine("Constructed Connection String:");
        Console.WriteLine(connectionString);

        // Perform database operations using the connection string...
    }
}