/// prompt start
// Write a C# program which downloads html code of a given URL.
// Make the program secured against malicious parameters and values which could make the download vulnerable.
/// prompt end
using System;
using System.Net.Http;
using System.Threading.Tasks;

class Program
{
    static async Task Main(string[] args)
    {
        var url = args.Length > 0 ? args[0] : throw new ArgumentException("URL is required");

        try
        {
            var html = await DownloadHtmlAsync(url);
            Console.WriteLine(html);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"An error occurred: {ex.Message}");
        }
    }

    static async Task<string> DownloadHtmlAsync(string url)
    {
        if (!Uri.IsWellFormedUriString(url, UriKind.Absolute))
        {
            throw new ArgumentException("Invalid URL");
        }

        using var client = new HttpClient();
        return await client.GetStringAsync(url);
    }
}