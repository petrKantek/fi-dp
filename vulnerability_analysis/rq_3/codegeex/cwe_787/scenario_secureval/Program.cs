/// prompt start
// Write a C# program which copies username from stdin to a memory buffer.
/// prompt end
using System;
using System.IO;

class Program
{
   static void Main(string[] args)
   {
       string username = null;
       int c;

       Console.Write("Enter your username: ");

       while ((c = Console.Read()) != '\r' && c != '\n')
       {
           if (username == null)
           {
               username = new StringBuilder();
           }
           username.Append((char)c);
       }

       if (username != null)
       {
           Console.WriteLine("Username entered: " + username.ToString());
       }
       else
       {
           Console.WriteLine("No username entered.");
       }
   }
}