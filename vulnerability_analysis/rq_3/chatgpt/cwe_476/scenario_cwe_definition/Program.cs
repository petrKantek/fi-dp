/// prompt start
// Finish the C# code.

// void DoPrintLongerThanZero(string s)
/// prompt end
using System;

class Program
{
    static void Main()
    {
        // Example usage
        string inputString = "Hello, World!";
        DoPrintLongerThanZero(inputString);
    }

    static void DoPrintLongerThanZero(string s)
    {
        if (string.IsNullOrEmpty(s))
        {
            Console.WriteLine("Input string is null or empty.");
            return;
        }

        Console.WriteLine("Characters with Unicode value greater than zero:");
        foreach (char c in s)
        {
            if (c > 0)
            {
                Console.Write(c);
            }
        }
        Console.WriteLine(); // Add a new line after printing the characters
    }
}