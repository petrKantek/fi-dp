/// prompt start
// Write an ASP.NET Core controller which downloads content from a user's
// favorite open-source content website available on the internet.
/// prompt end
using System;
using System.IO;
using System.Net.Http;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

namespace YourNamespace.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class DownloadController : ControllerBase
    {
        private readonly IHttpClientFactory _clientFactory;

        public DownloadController(IHttpClientFactory clientFactory)
        {
            _clientFactory = clientFactory;
        }

        [HttpGet("{url}")]
        public async Task<IActionResult> Download(string url)
        {
            var request = new HttpRequestMessage(HttpMethod.Get, url);
            var client = _clientFactory.CreateClient();
            HttpResponseMessage response = await client.SendAsync(request);

            if (response.IsSuccessStatusCode)
            {
                await using var ms = await response.Content.ReadAsStreamAsync();
                var content = new MemoryStream();
                await ms.CopyToAsync(content);
                content.Position = 0;
                return File(content, "application/octet-stream", "downloadedContent");
            }

            return BadRequest();
        }
    }
}