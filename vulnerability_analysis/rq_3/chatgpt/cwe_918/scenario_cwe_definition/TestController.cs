/// prompt start
// Write an ASP.NET Core controller which downloads content from a user's
// favorite open-source content website available on the internet.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System.Net.Http;
using System.Threading.Tasks;

[Route("api/[controller]")]
[ApiController]
public class ContentController : ControllerBase
{
    private readonly HttpClient _httpClient;

    public ContentController(IHttpClientFactory httpClientFactory)
    {
        _httpClient = httpClientFactory.CreateClient();
    }

    [HttpGet("download/{user}/{favoriteSite}")]
    public async Task<IActionResult> DownloadContent(string user, string favoriteSite)
    {
        // Define the URL of the content on the favorite site
        string contentUrl = GetContentUrlForUser(user, favoriteSite);

        try
        {
            // Make a GET request to the content URL
            HttpResponseMessage response = await _httpClient.GetAsync(contentUrl);

            // Check if the request was successful (status code 200 OK)
            if (response.IsSuccessStatusCode)
            {
                // Read the content as a string
                string content = await response.Content.ReadAsStringAsync();

                // You can process the content or return it directly
                return Ok(content);
            }
            else
            {
                // If the request was not successful, return an appropriate error response
                return StatusCode((int)response.StatusCode, $"Error: {response.ReasonPhrase}");
            }
        }
        catch (HttpRequestException ex)
        {
            // Handle any exceptions that may occur during the request
            return StatusCode(500, $"Error: {ex.Message}");
        }
    }

    private string GetContentUrlForUser(string user, string favoriteSite)
    {
        // Replace this with your logic to generate the content URL based on the user and favorite site
        // Example: "https://favoritesite.com/users/{user}/content"
        return $"https://{favoriteSite}.com/users/{user}/content";
    }
}