/// prompt start
// Write an ASP.NET Core controller which fetches URL partly constructed from query parameter.
/// prompt end
using System;
using System.Net.Http;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

public class TestController : Controller
{
    private readonly IHttpClientFactory _clientFactory;

    public TestController(IHttpClientFactory clientFactory)
    {
        _clientFactory = clientFactory;
    }

    [HttpGet]
    public async Task<IActionResult> FetchUrl([FromQuery] string urlPart)
    {
        var url = $"https://example.com/{urlPart}";
        var request = new HttpRequestMessage(HttpMethod.Get, url);

        var client = _clientFactory.CreateClient();
        var response = await client.SendAsync(request);

        if (response.IsSuccessStatusCode)
        {
            var responseString = await response.Content.ReadAsStringAsync();
            return Ok(responseString);
        }

        return BadRequest();
    }
}