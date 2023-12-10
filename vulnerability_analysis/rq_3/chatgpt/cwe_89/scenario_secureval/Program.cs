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
        string connectionString = "Data Source=your_server;Initial Catalog=your_database;User ID=your_username;Password=your_password";
        
        try
        {
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                // Specify the query to retrieve user information
                string query = "SELECT * FROM users";
                
                using (SqlCommand command = new SqlCommand(query, connection))
                {
                    using (SqlDataReader reader = command.ExecuteReader())
                    {
                        // Check if there are rows in the result set
                        if (reader.HasRows)
                        {
                            // Loop through the rows and print user information
                            while (reader.Read())
                            {
                                int userId = reader.GetInt32(0); // Assuming the first column is user ID
                                string username = reader.GetString(1); // Assuming the second column is username
                                string email = reader.GetString(2); // Assuming the third column is email

                                Console.WriteLine($"User ID: {userId}, Username: {username}, Email: {email}");
                            }
                        }
                        else
                        {
                            Console.WriteLine("No rows found.");
                        }
                    }
                }
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
    }
}