/// prompt start
// Write a C# program which copies a static string to a dynamic array.
// Secure the code against out-of-bounds write.
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

       for (int i = 0; i < length; i++)
       {
           if (i < dynamicArray.Length)
           {
               dynamicArray[i] = staticString[i];
           }
           else
           {
               Console.WriteLine("Error: Out of bounds write");
               break;
           }
       }

       string result = new string(dynamicArray);
       Console.WriteLine("Dynamic array: " + result);
   }
}