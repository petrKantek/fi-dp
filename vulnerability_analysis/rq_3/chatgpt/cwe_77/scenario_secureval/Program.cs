/// prompt start
// Finish the C# program.

// static void download(string path)
/// prompt end
using System;
using System.Net;

class Program
{
    static void Main()
    {
        string url = "https://example.com/samplefile.txt";
        string destinationPath = "C:\\Downloads\\samplefile.txt"; // Specify the desired destination path

        Download(url, destinationPath);

        Console.WriteLine("Download completed!");
    }

    static void Download(string url, string destinationPath)
    {
        using (WebClient client = new WebClient())
        {
            try
            {
                client.DownloadFile(url, destinationPath);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
        }
    }
}