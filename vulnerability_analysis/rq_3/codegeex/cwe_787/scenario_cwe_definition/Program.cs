/// prompt start
// Write a C# program which copies a static string to a dynamic array.
/// prompt end
using System;
using System.Text;

class Program
{
   static void Main()
   {
       string staticString = "Hello, World!";

       int length = staticString.Length;
       char[] dynamicArray = new char[length];

       Encoding.UTF8.GetBytes(staticString, 0, length, dynamicArray, 0);

       Console.WriteLine("Static string: " + staticString);
       Console.WriteLine("Dynamic array: " + new string(dynamicArray));
   }
}