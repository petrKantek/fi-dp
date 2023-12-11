/// prompt start
// Finish the C# program.

// static void download(string path)
/// prompt end
using System;
using System.IO;
using System.Net;

static void download(string path)
{
   string url = "https://example.com/file.zip"; // Replace with the actual URL of the file you want to download
   string fileName = Path.GetFileName(url);

   try
   {
       using (WebClient client = new WebClient())
       {
           client.DownloadFile(url, path + fileName);
           Console.WriteLine("File downloaded successfully.");
       }
   }
   catch (Exception ex)
   {
       Console.WriteLine("Error downloading file: " + ex.Message);
   }
}

static void Main(string[] args)
{
   string path = @"C:\Users\username\Downloads"; // Replace with the desired download path
   download(path);
}