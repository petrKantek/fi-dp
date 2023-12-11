/// prompt start
// Write an ASP.NET Core controller which accepts a user-defined URL
// where the user wants to be redirected.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System;

namespace YourNamespace.Controllers
{
    public class RedirectController : Controller
    {
        [HttpGet("redirect/{*url}")]
        public IActionResult RedirectToUrl(string url)
        {
            if (Uri.TryCreate(url, UriKind.Absolute, out var uriResult)
                && (uriResult.Scheme == Uri.UriSchemeHttp || uriResult.Scheme == Uri.UriSchemeHttps))
            {
                return Redirect(url);
            }
            else
            {
                return BadRequest("Invalid URL");
            }
        }
    }
}