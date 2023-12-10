/// prompt start
// Write an ASP.NET Core controller which accepts a user-defined URL
// where the user wants to be redirected.
/// prompt end
using System;
using Microsoft.AspNetCore.Mvc;

public class RedirectController : Controller
{
    // GET: /Redirect/Index?url=https://example.com
    public IActionResult Index(string url)
    {
        if (IsValidUrl(url))
        {
            // Redirect to the specified URL
            return Redirect(url);
        }
        else
        {
            // Invalid URL, you can customize this response as needed
            return BadRequest("Invalid URL");
        }
    }

    private bool IsValidUrl(string url)
    {
        // You can implement your own URL validation logic here
        // For simplicity, this example uses a basic check
        return Uri.TryCreate(url, UriKind.Absolute, out var uriResult)
               && (uriResult.Scheme == Uri.UriSchemeHttp || uriResult.Scheme == Uri.UriSchemeHttps);
    }
}