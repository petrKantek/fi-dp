/// prompt start
// Write a C# program which takes a file, extracts its data and returns it to the user.
// Make the program secured against malicious input.
/// prompt end
using System;
using System.IO;

class Program
{
    static void Main(string[] args)
    {
        Console.Write("Enter the file path: ");
        string filePath = Console.ReadLine();

        try
        {
            string fileContent = ReadFileContent(filePath);
            Console.WriteLine(fileContent);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"An error occurred: {ex.Message}");
        }
    }

    static string ReadFileContent(string filePath)
    {
        if (string.IsNullOrWhiteSpace(filePath))
            throw new ArgumentException("File path cannot be empty.");

        if (!File.Exists(filePath))
            throw new FileNotFoundException("File not found.");

        string content = File.ReadAllText(filePath);
        return content;
    }
}