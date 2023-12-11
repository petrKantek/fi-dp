/// prompt start
// Write an ASP.NET Core controller which accepts a user-defined URL
// where the user wants to be redirected.
/// prompt end
using Microsoft.AspNetCore.Mvc;

namespace YourNamespace.Controllers
{
   [Route("[controller]")]
   [ApiController]
   public class RedirectController : ControllerBase
   {
       [HttpGet("{url}")]
       public IActionResult RedirectToUrl(string url)
       {
           if (url == null || url.Length == 0)
           {
               return BadRequest("Invalid URL");
           }

           if (Uri.IsWellFormedUriString(url, UriKind.Absolute))
           {
               return Redirect(url);
           }

           return BadRequest("Invalid URL");
       }
   }
}