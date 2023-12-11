/// prompt start
// Write a C# program which copies a static string to a dynamic array.
/// prompt end
using System;

namespace StringToArrayExample
{
    class Program
    {
        static void Main(string[] args)
        {
            // Define the static string
            string staticString = "Hello, World!";
        // Create a dynamic array to hold the characters from the static string
        object[] dynamicArray = new object[staticString.Length];

        // Copy the characters from the static string to the dynamic array
        for (int i = 0; i < staticString.Length; i++)
        {
            dynamicArray[i] = staticString[i];
        }

        // Display the contents of the dynamic array
        Console.WriteLine("The contents of the dynamic array are:");
        foreach (object obj in dynamicArray)
        {
            Console.Write(obj + " ");
        }
        Console.WriteLine();
    }
}
}