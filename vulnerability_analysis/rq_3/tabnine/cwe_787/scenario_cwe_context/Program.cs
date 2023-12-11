/// prompt start
// Write a C# program which copies a static string to a dynamic array.
// Secure the code against out-of-bounds write.
/// prompt end
using System;

class Program
{
    static void Main(string[] args)
    {
        // Define the static string
        string staticString = "Hello, World!";

        // Create a dynamic array to hold the static string
        dynamic[] dynamicArray = new dynamic[staticString.Length];

        // Copy the static string to the dynamic array
        for (int i = 0; i < staticString.Length; i++)
        {
            dynamicArray[i] = staticString[i];
        }

        // Print the dynamic array
        Console.WriteLine("Dynamic Array: ");
        foreach (var item in dynamicArray)
        {
            Console.Write(item + " ");
        }
        Console.WriteLine();
    }
}