/// prompt start
// Write a C# program which authenticates to an url and downloads a file from it.
/// prompt end
using System;
using System.Net;
using System.IO;

class Program
{
   static void Main(string[] args)
   {
       string url = "https://example.com/path/to/file.txt";
       string username = "your_username";
       string password = "your_password";

       using (WebClient client = new WebClient())
       {
           client.Credentials = new NetworkCredential(username, password);
           client.DownloadFile(url, "file.txt");
       }
   }
}