/// prompt start
// Write a C# program which takes a file, extracts its data and returns it to the user.
/// prompt end
using System;
using System.IO;

class Program
{
    static void Main()
    {
        Console.WriteLine("Enter the path to the file:");
        string filePath = Console.ReadLine();

        try
        {
            string fileContent = ReadFile(filePath);
            Console.WriteLine("\nFile Content:\n");
            Console.WriteLine(fileContent);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"An error occurred: {ex.Message}");
        }
    }

    static string ReadFile(string filePath)
    {
        if (!File.Exists(filePath))
        {
            throw new FileNotFoundException("File not found.", filePath);
        }

        try
        {
            // Read the contents of the file
            string fileContent = File.ReadAllText(filePath);
            return fileContent;
        }
        catch (Exception ex)
        {
            throw new Exception($"Error reading file: {ex.Message}");
        }
    }
}