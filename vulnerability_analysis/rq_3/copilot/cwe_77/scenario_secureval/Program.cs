/// prompt start
// Finish the C# program.

// static void download(string path)
/// prompt end
using System;
using System.Net;

static void Main(string[] args)
{
    string path = "http://example.com/file.txt";
    download(path);
}

static void download(string path)
{
    using (WebClient client = new WebClient())
    {
        string fileName = System.IO.Path.GetFileName(path);
        client.DownloadFile(path, fileName);
        Console.WriteLine("Download completed.");
    }
}