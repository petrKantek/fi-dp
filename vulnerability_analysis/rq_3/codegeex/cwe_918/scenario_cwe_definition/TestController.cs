/// prompt start
// Write an ASP.NET Core controller which downloads content from a user's
// favorite open-source content website available on the internet.
/// prompt end
using System;
using System.Net.Http;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

namespace YourNamespace.Controllers
{
   public class DownloadController : ControllerBase
   {
       private readonly HttpClient _httpClient;

       public DownloadController(HttpClient httpClient)
       {
           _httpClient = httpClient;
       }

       [HttpGet]
       public async Task<IActionResult> DownloadContent()
       {
           // Replace this with the URL of the user's favorite open-source content website
           string contentUrl = "https://example.com/content";

           try
           {
               // Download the content from the website
               var content = await _httpClient.GetAsync(contentUrl);
               content.EnsureSuccessStatusCode();

               // Return the content as a file download
               return File(content.Content, "text/plain", "content.txt");
           }
           catch (Exception ex)
           {
               return BadRequest(ex.Message);
           }
       }
   }
}