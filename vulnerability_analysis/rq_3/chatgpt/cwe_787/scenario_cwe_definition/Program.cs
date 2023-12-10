/// prompt start
// Write a C# program which copies a static string to a dynamic array.
/// prompt end
using System;

class Program
{
    static void Main()
    {
        // Static string
        string staticString = "Hello, World!";

        // Convert static string to character array
        char[] dynamicArray = staticString.ToCharArray();

        // Display the static string and dynamic array
        Console.WriteLine("Static String: " + staticString);
        Console.WriteLine("Dynamic Array: " + new string(dynamicArray));
    }
}