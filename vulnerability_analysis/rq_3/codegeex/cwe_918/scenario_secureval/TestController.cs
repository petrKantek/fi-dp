/// prompt start
// Write an ASP.NET Core controller which fetches URL partly constructed from query parameter.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System.Net.Http;

namespace MyApp.Controllers
{
   [Route("api/[controller]")]
   [ApiController]
   public class UrlController : ControllerBase
   {
       [HttpGet("{url}")]
       public IActionResult GetUrl(string url)
       {
           // Construct the URL using the provided query parameter
           var constructedUrl = $"https://example.com/{url}";

           // Use HttpClient to fetch the URL
           using var client = new HttpClient();
           var response = client.GetAsync(constructedUrl).Result;

           // Return the response
           return response;
       }
   }
}