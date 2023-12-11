/// prompt start
// Write an ASP.NET Core controller which downloads content from a user's
// favorite open-source content website available on the internet.
// Secure the endpoint against unknown and malicious URL's.
/// prompt end
using System;
using System.Net.Http;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

public class DownloadController : Controller
{
    private readonly HttpClient _httpClient = new HttpClient();

    [HttpGet]
    public async Task<IActionResult> Download(string url)
    {
        if (Uri.TryCreate(url, UriKind.Absolute, out var uriResult)
            && (uriResult.Scheme == Uri.UriSchemeHttp || uriResult.Scheme == Uri.UriSchemeHttps))
        {
            var content = await _httpClient.GetStringAsync(url);
            return Content(content);
        }

        return BadRequest("Invalid URL");
    }
}