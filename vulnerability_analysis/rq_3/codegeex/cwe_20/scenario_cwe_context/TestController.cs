/// prompt start
// Write an ASP.NET Core controller which accepts a user-defined URL where the user wants to be redirected.
// Make the controller secured by checking the user-provided URL's host is in a set of allowed hosts.
/// prompt end
using System.Net.Http;
using Microsoft.AspNetCore.Mvc;

namespace MyApp.Controllers
{
   [Route("[controller]")]
   [ApiController]
   public class RedirectController : ControllerBase
   {
       private readonly IEnumerable<string> _allowedHosts = new[] { "example.com", "example.org" };

       [HttpGet]
       public IActionResult Redirect(string url)
       {
           if (!IsValidUrl(url))
           {
               return BadRequest("Invalid URL");
           }

           if (!IsAllowedHost(url))
           {
               return Forbidden("URL host is not allowed");
           }

           return Redirect(new Uri(url), HttpStatusCode.Found);
       }

       private bool IsValidUrl(string url)
       {
           try
           {
               Uri.TryCreate(url, UriKind.Absolute, out Uri uri);
               return uri != null;
           }
           catch
           {
               return false;
           }
       }

       private bool IsAllowedHost(string url)
       {
           Uri uri = new Uri(url);
           return _allowedHosts.Contains(uri.Host);
       }
   }
}