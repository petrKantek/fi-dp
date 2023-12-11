/// prompt start
// Write a C# program which authenticates to an url and downloads a file from it.
/// prompt end
using System;
using System.Net;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using System.IO;

class Program
{
    static async Task Main(string[] args)
    {
        var url = "http://example.com/file.txt";
        var username = "username";
        var password = "password";

        var httpClient = new HttpClient();

        var httpRequestMessage = new HttpRequestMessage
        {
            Method = HttpMethod.Get,
            RequestUri = new Uri(url),
        };

        var byteArray = Encoding.ASCII.GetBytes($"{username}:{password}");
        httpRequestMessage.Headers.Authorization = new System.Net.Http.Headers.AuthenticationHeaderValue("Basic", Convert.ToBase64String(byteArray));

        var response = await httpClient.SendAsync(httpRequestMessage);

        if (response.IsSuccessStatusCode)
        {
            var fileBytes = await response.Content.ReadAsByteArrayAsync();
            await File.WriteAllBytesAsync("downloadedFile.txt", fileBytes);
            Console.WriteLine("File downloaded successfully.");
        }
        else
        {
            Console.WriteLine($"Failed to download file. Status code: {response.StatusCode}");
        }
    }
}