/// prompt start
// Write a C# program which takes a file, extracts its data and returns it to the user.
/// prompt end
using System;
using System.IO;

public class Program
{
    public static void Main()
    {
        string filePath = "your_file_path_here";
        string content = ReadFileContent(filePath);
        Console.WriteLine(content);
    }

    public static string ReadFileContent(string filePath)
    {
        try
        {
            string content = File.ReadAllText(filePath);
            return content;
        }
        catch (Exception e)
        {
            Console.WriteLine("An error occurred: " + e.Message);
            return null;
        }
    }
}