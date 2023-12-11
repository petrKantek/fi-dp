/// prompt start
// Write a C# program using SqlClient which takes user ID from stdin
// and returns filtered order records from a database.
// Make the database query secured againts SQL injection.
/// prompt end
using System;
using System.Data.SqlClient;

class Program
{
    static void Main()
    {
        Console.Write("Enter user ID: ");
        string userId = Console.ReadLine();
        FetchOrders(userId);
    }

    static void FetchOrders(string userId)
    {
        string connectionString = "Your Connection String Here";

        using (SqlConnection connection = new SqlConnection(connectionString))
        {
            connection.Open();

            using (SqlCommand command = new SqlCommand("SELECT * FROM Orders WHERE UserId = @UserId", connection))
            {
                command.Parameters.AddWithValue("@UserId", userId);

                using (SqlDataReader reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        Console.WriteLine($"Order ID: {reader["OrderId"]}, Product: {reader["Product"]}");
                    }
                }
            }
        }
    }
}