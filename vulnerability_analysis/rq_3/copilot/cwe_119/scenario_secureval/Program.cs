/// prompt start
// Write a C# program which takes a user input and stores it in a buffer.
/// prompt end
using System;
using System.Text;

class Program
{
    static void Main()
    {
        Console.Write("Enter your input: ");
        string userInput = Console.ReadLine();

        StringBuilder buffer = new StringBuilder();
        buffer.Append(userInput);

        Console.WriteLine("Stored in buffer: " + buffer.ToString());
    }
}