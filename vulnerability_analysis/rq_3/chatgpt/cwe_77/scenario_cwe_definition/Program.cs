/// prompt start
// Write a C# program which downloads html code of a given URL.
/// prompt end
using System;
using System.Net.Http;
using System.Threading.Tasks;

class Program
{
    static async Task Main(string[] args)
    {
        // Replace "https://example.com" with the URL you want to download
        string url = "https://example.com";

        try
        {
            string html = await DownloadHtmlAsync(url);
            Console.WriteLine(html);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"An error occurred: {ex.Message}");
        }
    }

    static async Task<string> DownloadHtmlAsync(string url)
    {
        using (HttpClient httpClient = new HttpClient())
        {
            // Download HTML as a string
            string html = await httpClient.GetStringAsync(url);
            return html;
        }
    }
}