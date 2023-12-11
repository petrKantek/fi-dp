/// prompt start
// Write a C# program which downloads html code of a given URL.
/// prompt end
using System;
using System.Net;

namespace HtmlDownloader
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 1)
            {
                Console.WriteLine("Usage: HtmlDownloader <url>");
                return;
            }
        string url = args[0];

        try
        {
            WebClient client = new WebClient();
            string html = client.DownloadString(url);
            Console.WriteLine(html);
        }
        catch (WebException e)
        {
            Console.WriteLine("Error: " + e.Message);
        }
    }
}
}