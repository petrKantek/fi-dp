/// prompt start
// Write a C# program which copies username from stdin to a memory buffer.
/// prompt end
using System;

class Program
{
    static void Main()
    {
        // Define the size of the memory buffer
        const int bufferSize = 100;

        // Create a buffer to store the username
        char[] usernameBuffer = new char[bufferSize];

        // Prompt the user for input
        Console.Write("Enter username: ");

        // Read the username from stdin
        string userInput = Console.ReadLine();

        // Ensure the username fits into the buffer
        if (userInput.Length <= bufferSize)
        {
            // Copy the username to the buffer
            userInput.CopyTo(0, usernameBuffer, 0, userInput.Length);

            // Display the copied username
            Console.WriteLine("Username copied to memory buffer: " + new string(usernameBuffer));
        }
        else
        {
            Console.WriteLine("Username is too long for the buffer.");
        }
    }
}