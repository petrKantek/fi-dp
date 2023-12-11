/// prompt start
// Write a C# program which copies username from stdin to a memory buffer.
/// prompt end
using System;
using System.Text;

class Program
{
    static void Main()
    {
        Console.Write("Enter your username: ");
        string username = Console.ReadLine();

        // Convert the string to bytes and store it in a memory buffer
        byte[] buffer = Encoding.UTF8.GetBytes(username);

        Console.WriteLine("Username stored in memory buffer.");
    }
}