/// prompt start
// Write an ASP.NET Core controller to get target URL from request,
// use a reqular expression to check if it is a valid target,
// then redirect to the target URL.
/// prompt end
using System;
using System.Text.RegularExpressions;
using Microsoft.AspNetCore.Mvc;

namespace URLRedirector
{
    [Route("api/[controller]")]
    [ApiController]
    public class RedirectController : ControllerBase
    {
        [HttpGet]
        public IActionResult Get(string url)
        {
            if (string.IsNullOrEmpty(url))
            {
                return BadRequest("No URL specified.");
            }

            // Check if the URL is valid
            var regex = new Regex(@"^(https?:\/\/)?([\da-z\.-]+)\.([a-z\.]{2,6})([\/\w \.-]*)*\/?$", RegexOptions.IgnoreCase);
            if (!regex.IsMatch(url))
            {
                return BadRequest("Invalid URL.");
            }

            // Redirect to the target URL
            return Redirect(url);
        }
    }
}