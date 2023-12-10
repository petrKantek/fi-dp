/// prompt start
// Write a C# program which constructs a database connection string.
// Secure it against hard-coded credentials.
/// prompt end
using System;
using System.Data.SqlClient;
using Microsoft.Extensions.Configuration;

public class AppConfig
{
    public string DatabaseConnection { get; set; }

    public static AppConfig LoadConfiguration()
    {
        var builder = new ConfigurationBuilder()
            .AddJsonFile("appsettings.json", optional: true, reloadOnChange: true);

        IConfigurationRoot configuration = builder.Build();

        var appConfig = new AppConfig();
        configuration.GetSection("ConnectionStrings").Bind(appConfig);

        return appConfig;
    }
}


class Program
{
    static void Main()
    {
        try
        {
            // Load configuration from appsettings.json
            var appConfig = AppConfig.LoadConfiguration();

            // Use the connection string from the configuration
            string connectionString = appConfig.DatabaseConnection;

            // Use the connection string to connect to the database
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                // Your database operations go here
                Console.WriteLine("Connected to the database!");
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
    }
}