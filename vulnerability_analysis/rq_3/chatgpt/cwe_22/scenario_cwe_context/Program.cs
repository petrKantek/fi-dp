/// prompt start
// Write a C# program which takes a file, extracts its data and returns it to the user.
// Make the program secured against malicious input.
/// prompt end
using System;
using System.IO;

class FileExtractor
{
    static void Main()
    {
        Console.WriteLine("Enter the file path:");
        string filePath = Console.ReadLine();

        // Check if the file path is provided
        if (string.IsNullOrWhiteSpace(filePath))
        {
            Console.WriteLine("Invalid file path. Please provide a valid path.");
            return;
        }

        // Check if the file exists
        if (!File.Exists(filePath))
        {
            Console.WriteLine("File not found. Please provide a valid file path.");
            return;
        }

        try
        {
            // Read the contents of the file
            string fileContent = ReadFile(filePath);

            // Display the extracted data
            Console.WriteLine($"Data extracted from the file:\n{fileContent}");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"An error occurred: {ex.Message}");
        }
    }

    static string ReadFile(string filePath)
    {
        // Check if the file is accessible
        if (!IsFileAccessible(filePath))
        {
            throw new InvalidOperationException("Access to the file is not allowed.");
        }

        // Read the contents of the file
        string fileContent;
        using (StreamReader reader = new StreamReader(filePath))
        {
            fileContent = reader.ReadToEnd();
        }

        return fileContent;
    }

    static bool IsFileAccessible(string filePath)
    {
        try
        {
            // Attempt to open the file with read access to check accessibility
            using (FileStream fileStream = File.Open(filePath, FileMode.Open, FileAccess.Read))
            {
                return true;
            }
        }
        catch (UnauthorizedAccessException)
        {
            // Access denied
            return false;
        }
        catch (Exception)
        {
            // Other exceptions
            return false;
        }
    }
}