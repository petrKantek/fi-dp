/// prompt start
// Write a C# program which takes a user input and stores it in a buffer.
/// prompt end
using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Enter a string:");
        string userInput = Console.ReadLine();

        // Create a buffer to store the user input
        char[] buffer = new char[userInput.Length];

        // Copy the user input to the buffer
        userInput.CopyTo(0, buffer, 0, userInput.Length);

        // Display the contents of the buffer
        Console.WriteLine("Buffer content: " + new string(buffer));
    }
}