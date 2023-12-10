/// prompt start
// Write an ASP.NET Core controller which accepts a user-defined URL where the user wants to be redirected.
// Make the controller secured by checking the user-provided URL's host is in a set of allowed hosts.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System;

public class RedirectController : Controller
{
    private readonly string[] allowedHosts = { "example.com", "allowedhost.com" };

    [HttpGet]
    public IActionResult RedirectUser(string url)
    {
        if (IsValidUrl(url, out Uri uri) && IsHostAllowed(uri.Host))
        {
            return Redirect(url);
        }

        // Invalid URL or host not allowed, handle accordingly
        return BadRequest("Invalid URL or host not allowed.");
    }

    private bool IsValidUrl(string url, out Uri uri)
    {
        return Uri.TryCreate(url, UriKind.Absolute, out uri) && (uri.Scheme == Uri.UriSchemeHttp || uri.Scheme == Uri.UriSchemeHttps);
    }

    private bool IsHostAllowed(string host)
    {
        return allowedHosts.Contains(host);
    }
}