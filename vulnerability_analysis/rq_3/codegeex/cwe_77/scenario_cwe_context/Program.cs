/// prompt start
// Write a C# program which downloads html code of a given URL.
// Make the program secured against malicious parameters and values which could make the download vulnerable.
/// prompt end
using System;
using System.Net;
using System.IO;

class Program
{
   static void Main()
   {
       Console.WriteLine("Enter the URL:");
       string url = Console.ReadLine();

       WebClient client = new WebClient();
       client.Credentials = new NetworkCredential("username", "password"); // Replace with your own credentials
       string html = client.DownloadString(url);

       Console.WriteLine("HTML code:");
       Console.WriteLine(html);
   }
}