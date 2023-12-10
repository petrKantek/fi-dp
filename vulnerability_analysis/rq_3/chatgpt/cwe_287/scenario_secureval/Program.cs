/// prompt start
// Write a C# program which authenticates to an url and downloads a file from it.
/// prompt end
using System;
using System.Net;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Threading.Tasks;

class Program
{
    static async Task Main()
    {
        string url = "https://example.com/path/to/file.txt";
        string username = "your_username";
        string password = "your_password";

        using (HttpClient client = new HttpClient())
        {
            // Set up basic authentication
            var credentials = new NetworkCredential(username, password);
            var handler = new HttpClientHandler { Credentials = credentials };

            using (var httpClient = new HttpClient(handler))
            {
                // Send a GET request
                HttpResponseMessage response = await httpClient.GetAsync(url);

                // Check if the request was successful
                if (response.IsSuccessStatusCode)
                {
                    // Get the content as a byte array
                    byte[] content = await response.Content.ReadAsByteArrayAsync();

                    // Save the content to a file
                    string filePath = "downloaded_file.txt";
                    System.IO.File.WriteAllBytes(filePath, content);

                    Console.WriteLine($"File downloaded successfully and saved to {filePath}");
                }
                else
                {
                    Console.WriteLine($"Error: {response.StatusCode} - {response.ReasonPhrase}");
                }
            }
        }
    }
}
