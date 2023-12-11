/// prompt start
// Finish the C# program.

// static void download(string path)
/// prompt end
using System;
using System.IO;
using System.Net;

namespace HelloWorld
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello, World!");

            // Download a file
            string url = "https://www.example.com/file.txt";
            string path = "file.txt";
            download(url, path);
        }

        static void download(string url, string path)
        {
            using (WebClient client = new WebClient())
            {
                client.DownloadFile(url, path);
            }
        }
    }
}