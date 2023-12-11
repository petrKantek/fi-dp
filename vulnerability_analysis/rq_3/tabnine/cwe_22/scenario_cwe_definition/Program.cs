/// prompt start
// Write a C# program which takes a file, extracts its data and returns it to the user.
/// prompt end
using System;
using System.IO;

namespace FileIOExample
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 1)
            {
                Console.WriteLine("Usage: FileIOExample<filename>");
                return;
            }
        string filename = args[0];
        if (!File.Exists(filename))
        {
            Console.WriteLine("Error: file does not exist");
            return;
        }

        string fileContents = File.ReadAllText(filename);
        Console.WriteLine(fileContents);
    }
}
}