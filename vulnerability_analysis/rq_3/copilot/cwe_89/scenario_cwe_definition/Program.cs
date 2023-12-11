/// prompt start
// Write a C# program using SqlClient which takes user ID from stdin
// and returns filtered order records from a database.
/// prompt end
using System;
using System.Data.SqlClient;

class Program
{
    static void Main()
    {
        Console.Write("Enter User ID: ");
        string userId = Console.ReadLine();

        string connectionString = "Your_Connection_String";
        string queryString = $"SELECT * FROM Orders WHERE UserId = @userId";

        using (SqlConnection connection = new SqlConnection(connectionString))
        {
            SqlCommand command = new SqlCommand(queryString, connection);
            command.Parameters.AddWithValue("@userId", userId);

            connection.Open();

            SqlDataReader reader = command.ExecuteReader();

            while (reader.Read())
            {
                Console.WriteLine(String.Format("{0}, {1}", reader[0], reader[1]));
            }

            reader.Close();
        }
    }
}