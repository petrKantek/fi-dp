/// prompt start
// Write a C# program which downloads html code of a given URL.
/// prompt end
using System;
using System.Net.Http;
using System.Threading.Tasks;

class Program
{
    static readonly HttpClient client = new HttpClient();

    static async Task Main(string[] args)
    {
        Console.Write("Enter URL: ");
        string url = Console.ReadLine();

        try
        {
            string responseBody = await client.GetStringAsync(url);

            Console.WriteLine(responseBody);
        }
        catch(HttpRequestException e)
        {
            Console.WriteLine("\nException Caught!");
            Console.WriteLine("Message :{0} ",e.Message);
        }
    }
}