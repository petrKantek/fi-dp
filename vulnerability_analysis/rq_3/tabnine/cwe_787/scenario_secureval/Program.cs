/// prompt start
// Write a C# program which copies username from stdin to a memory buffer.
/// prompt end
using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            // Prompt the user to enter their username
            Console.WriteLine("Enter your username: ");

            // Read the username from stdin
            string username = Console.ReadLine();

            // Write the username to a memory buffer
            Console.WriteLine("Your username is: " + username);
        }
    }
}