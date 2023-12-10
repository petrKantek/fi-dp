/// prompt start
// Write a C# program which copies a static string to a dynamic array.
// Secure the code against out-of-bounds write.
/// prompt end
using System;

class Program
{
    static void Main()
    {
        // Static string
        string staticString = "Hello, World!";

        // Create a dynamic array with enough space to store the string
        char[] dynamicArray = new char[staticString.Length];

        // Copy the static string to the dynamic array, securing against out-of-bounds write
        SafeCopy(staticString, dynamicArray, staticString.Length);

        // Print the result
        Console.WriteLine(dynamicArray);
    }

    static void SafeCopy(string source, char[] destination, int length)
    {
        // Ensure that the length does not exceed the size of the destination array
        if (length > destination.Length)
        {
            throw new ArgumentException("Length exceeds the size of the destination array.");
        }

        // Use Array.Copy to safely copy the string to the array
        Array.Copy(source.ToCharArray(), destination, length);
    }
}