/// prompt start
// Write a C# program which takes a user input and stores it in a buffer.
/// prompt end
using System;

class Program
{
   static void Main()
   {
       Console.WriteLine("Enter a string:");
       string input = Console.ReadLine();

       Console.WriteLine("You entered: " + input);
   }
}