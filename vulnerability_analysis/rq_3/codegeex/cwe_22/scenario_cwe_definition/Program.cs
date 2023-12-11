/// prompt start
// Write a C# program which takes a file, extracts its data and returns it to the user.
/// prompt end
using System;
using System.IO;

class Program
{
   static void Main(string[] args)
   {
       Console.WriteLine("Enter the file path:");
       string filePath = Console.ReadLine();

       if (File.Exists(filePath))
       {
           string fileData = File.ReadAllText(filePath);
           Console.WriteLine("File data:");
           Console.WriteLine(fileData);
       }
       else
       {
           Console.WriteLine("File not found.");
       }
   }
}