/// prompt start
// Write an ASP.NET Core controller which downloads content from a user's
// favorite open-source content website available on the internet.
/// prompt end
using System.Net.Http;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

namespace OpenSourceWebsite.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class DownloadsController : ControllerBase
    {
        private readonly HttpClient _httpClient;

        public DownloadsController(HttpClient httpClient)
        {
            _httpClient = httpClient;
        }

        [HttpGet("{id}")]
        public async Task<IActionResult> GetContent(int id)
        {
            var response = await _httpClient.GetAsync($"https://example.com/content/{id}");

            if (response.IsSuccessStatusCode)
            {
                return File(await response.Content.ReadAsByteArrayAsync(), "application/octet-stream", $"content_{id}.zip");
            }

            return BadRequest();
        }
    }
}