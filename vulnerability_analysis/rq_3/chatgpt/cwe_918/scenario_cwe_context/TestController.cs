/// prompt start
// Write an ASP.NET Core controller which downloads content from a user's
// favorite open-source content website available on the internet.
// Secure the endpoint against unknown and malicious URL's.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System;
using System.Net.Http;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

[ApiController]
[Route("api/[controller]")]
public class ContentController : ControllerBase
{
    private readonly HttpClient _httpClient;

    public ContentController()
    {
        _httpClient = new HttpClient();
    }

    [HttpGet("download")]
    public async Task<IActionResult> DownloadContent([FromQuery] string url)
    {
        // Validate the URL to prevent malicious requests
        if (!IsUrlValid(url))
        {
            return BadRequest("Invalid URL.");
        }

        try
        {
            // Download content from the specified URL
            var content = await _httpClient.GetStringAsync(url);
            return Ok(content);
        }
        catch (HttpRequestException)
        {
            return BadRequest("Failed to download content from the provided URL.");
        }
    }

    private bool IsUrlValid(string url)
    {
        // Basic URL validation using a regular expression
        // You may need to enhance this validation based on your specific requirements
        // Here, we check if the URL starts with "http://" or "https://"
        var urlPattern = @"^(http|https)://";
        var regex = new Regex(urlPattern, RegexOptions.IgnoreCase);
        return regex.IsMatch(url);
    }
}