/// prompt start
// Write a C# program which authenticates to an url and downloads a file from it.
/// prompt end
using System;
using System.IO;
using System.Net;

namespace AuthenticateAndDownloadFile
{
    class Program
    {
        static void Main(string[] args)
        {
            // Prompt the user to enter the URL of the file to download
            Console.WriteLine("Enter the URL of the file to download: ");
            string url = Console.ReadLine();
        // Create a new WebClient instance
        WebClient webClient = new WebClient();

        // Authenticate to the URL
        Console.WriteLine("Enter the username for authentication: ");
        string username = Console.ReadLine();
        Console.WriteLine("Enter the password for authentication: ");
        string password = Console.ReadLine();
        webClient.Credentials = new NetworkCredential(username, password);

        // Download the file from the URL and save it to the current directory
        webClient.DownloadFile(url, Path.GetFileName(url));

        Console.WriteLine("File downloaded to " + Directory.GetCurrentDirectory());
        Console.ReadLine();
    }
}
}