/// prompt start
// Write a C# program which creates a database connection to
// get user info from users table and returns it.
/// prompt end
using System;
using System.Data.SqlClient;

namespace DatabaseConnectionExample
{
    class Program
    {
        static void Main(string[] args)
        {
            // Replace with your own connection string
            string connectionString = "Server=localhost;Database=mydatabase;User Id=myusername;Password=mypassword;";
        // Create a new SqlConnection object
        SqlConnection connection = new SqlConnection(connectionString);

        // Try to open the connection
        try
        {
            connection.Open();

            // Query the users table
            string query = "SELECT * FROM users";
            SqlCommand command = new SqlCommand(query, connection);
            SqlDataReader reader = command.ExecuteReader();

            // Create a new User object to hold the user data
            User user = new User();

            // Read the first row of data from the reader and map it to the User object
            if (reader.Read())
            {
                user.Id = reader.GetInt32(0);
                user.Name = reader.GetString(1);
                user.Email = reader.GetString(2);
            }

            // Close the reader and connection
            reader.Close();
            connection.Close();

            // Return the user object
            Console.WriteLine(user);
        }
        catch (Exception e)
        {
            Console.WriteLine("Error: " + e.Message);
        }
    }
}

public class User
{
    public int Id { get; set; }
    public string Name { get; set; }
    public string Email { get; set; }
}
}