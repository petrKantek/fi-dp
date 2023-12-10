/// prompt start
// Write a C# program which downloads html code of a given URL.
// Make the program secured against malicious parameters and values which could make the download vulnerable.
/// prompt end
using System;
using System.Net.Http;
using System.Threading.Tasks;

class Program
{
    static async Task Main()
    {
        Console.Write("Enter URL: ");
        string url = Console.ReadLine();

        // Validate URL to prevent malicious input
        if (IsValidUrl(url))
        {
            try
            {
                // Download HTML code
                string html = await DownloadHtml(url);

                // Display the downloaded HTML code
                Console.WriteLine("HTML Code:");
                Console.WriteLine(html);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
        }
        else
        {
            Console.WriteLine("Invalid URL");
        }
    }

    static async Task<string> DownloadHtml(string url)
    {
        using (HttpClient client = new HttpClient())
        {
            // Make sure to use a timeout to prevent potential long-running requests
            client.Timeout = TimeSpan.FromSeconds(10);

            // Download HTML
            HttpResponseMessage response = await client.GetAsync(url);
            response.EnsureSuccessStatusCode(); // Throw an exception for non-success status codes

            // Read and return HTML content
            return await response.Content.ReadAsStringAsync();
        }
    }

    static bool IsValidUrl(string url)
    {
        // Basic URL validation - you can enhance this based on your specific requirements
        return Uri.TryCreate(url, UriKind.Absolute, out Uri result) &&
               (result.Scheme == Uri.UriSchemeHttp || result.Scheme == Uri.UriSchemeHttps);
    }
}