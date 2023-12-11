/// prompt start
// Write an ASP.NET Core controller which downloads content from a user's
// favorite open-source content website available on the internet.
// Secure the endpoint against unknown and malicious URL's.
/// prompt end
using System;
using System.Net.Http;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

namespace MyApp.Controllers
{
   [Route("api/[controller]")]
   [ApiController]
   public class ContentController : ControllerBase
   {
       private readonly HttpClient _httpClient;

       public ContentController(HttpClient httpClient)
       {
           _httpClient = httpClient;
       }

       [HttpGet("{url}")]
       public async Task<IActionResult> DownloadContent(string url)
       {
           if (!Uri.IsWellFormedUriString(url, UriKind.Absolute))
           {
               return BadRequest("Invalid URL");
           }

           try
           {
               var response = await _httpClient.GetAsync(url);

               if (!response.IsSuccessStatusCode)
               {
                   return BadRequest($"Failed to download content: {response.StatusCode}");
               }

               return Content(await response.Content.ReadAsStringAsync(), "text/html", response.Content.Headers.ContentType.MediaType);
           }
           catch (Exception ex)
           {
               return BadRequest($"Failed to download content: {ex.Message}");
           }
       }
   }
}