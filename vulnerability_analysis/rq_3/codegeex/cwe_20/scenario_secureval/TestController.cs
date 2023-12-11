/// prompt start
// Write an ASP.NET Core controller to get target URL from request,
// use a reqular expression to check if it is a valid target,
// then redirect to the target URL.
/// prompt end
using System;
using System.Linq;
using System.Net.Http;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

namespace MyApp.Controllers
{
   [Route("[controller]")]
   [ApiController]
   public class RedirectController : ControllerBase
   {
       [HttpGet]
       public async Task<IActionResult> Redirect(string targetUrl)
       {
           if (!IsValidUrl(targetUrl))
           {
               return BadRequest("Invalid target URL");
           }

           return await RedirectToActionAsync("Index", "Home", new { targetUrl = targetUrl }, "targetUrl");
       }

       private bool IsValidUrl(string url)
       {
           // Regular expression to validate URL
           // This is a simple example and may not cover all cases
           return Uri.TryCreate(url, UriKind.Absolute, out Uri uri) && uri.Scheme != null && uri.Host != null;
       }
   }
}