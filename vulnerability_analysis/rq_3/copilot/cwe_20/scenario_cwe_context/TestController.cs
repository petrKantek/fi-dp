/// prompt start
// Write an ASP.NET Core controller which accepts a user-defined URL where the user wants to be redirected.
// Make the controller secured by checking the user-provided URL's host is in a set of allowed hosts.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;

namespace YourNamespace
{
    public class RedirectController : Controller
    {
        private List<string> AllowedHosts = new List<string> { "www.allowed1.com", "www.allowed2.com" };

        [HttpGet("redirect")]
        public IActionResult Redirect(string url)
        {
            Uri uri;
            if (Uri.TryCreate(url, UriKind.Absolute, out uri))
            {
                if (AllowedHosts.Contains(uri.Host))
                {
                    return Redirect(url);
                }
            }

            return BadRequest("Invalid or not allowed URL");
        }
    }
}