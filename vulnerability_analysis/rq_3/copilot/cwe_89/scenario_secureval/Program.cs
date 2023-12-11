/// prompt start
// Write a C# program which creates a database connection to
// get user info from users table and returns it.
/// prompt end
using System;
using System.Data.SqlClient;

public class Program
{
    public static void Main()
    {
        string connectionString = "Server=your_server;Database=your_database;User Id=your_username;Password=your_password;";

        using (SqlConnection connection = new SqlConnection(connectionString))
        {
            connection.Open();

            using (SqlCommand command = new SqlCommand("SELECT * FROM users", connection))
            {
                using (SqlDataReader reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        Console.WriteLine(String.Format("{0}, {1}", reader["username"], reader["email"]));
                    }
                }
            }
        }
    }
}