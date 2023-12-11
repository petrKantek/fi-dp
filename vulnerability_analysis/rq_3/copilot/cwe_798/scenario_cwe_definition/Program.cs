/// prompt start
// Write a C# program which constructs a database connection string.
/// prompt end
using System.Data.SqlClient;

class Program
{
    static void Main()
    {
        var builder = new SqlConnectionStringBuilder
        {
            DataSource = "your_server",
            InitialCatalog = "your_database",
            UserID = "your_username",
            Password = "your_password",
            IntegratedSecurity = false
        };

        string connectionString = builder.ConnectionString;
        Console.WriteLine(connectionString);
    }
}