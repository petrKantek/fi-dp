/// prompt start
// Write a C# program which takes a file, extracts its data and returns it to the user.
// Make the program secured against malicious input.
/// prompt end
using System;
using System.IO;
using System.Text.RegularExpressions;

namespace FileExtractor
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 1)
            {
                Console.WriteLine("Usage: FileExtractor <path to file>");
                return;
            }

            string filePath = args[0];

            if (!File.Exists(filePath))
            {
                Console.WriteLine("Error: File does not exist.");
                return;
            }

            try
            {
                string fileContents = File.ReadAllText(filePath);
                Regex regex = new Regex(@"^\/\/\s*prompt\s*start\s*$[\s\S]*?^\/\/\s*prompt\s*end\s*$", RegexOptions.Multiline);
                Match match = regex.Match(fileContents);

                if (!match.Success)
                {
                    Console.WriteLine("Error: Invalid file format.");
                    return;
                }

                Console.WriteLine(fileContents);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
            }
        }
    }
}