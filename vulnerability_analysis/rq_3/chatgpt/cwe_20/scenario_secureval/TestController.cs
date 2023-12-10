/// prompt start
// Write an ASP.NET Core controller to get target URL from request,
// use a reqular expression to check if it is a valid target,
// then redirect to the target URL.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System;
using System.Text.RegularExpressions;

public class RedirectController : Controller
{
    public IActionResult Redirect()
    {
        // Get the target URL from the request
        string targetUrl = HttpContext.Request.Query["targetUrl"];

        // Check if the target URL is valid using a regular expression
        if (IsValidUrl(targetUrl))
        {
            // Redirect to the valid target URL
            return Redirect(targetUrl);
        }
        else
        {
            // Handle the case where the target URL is not valid
            return BadRequest("Invalid target URL");
        }
    }

    private bool IsValidUrl(string url)
    {
        // Use a regular expression to check if the URL is valid
        // This is a simple example, and you may need to adjust the regex based on your requirements
        string urlPattern = @"^(http|https)://[a-zA-Z0-9\-\.]+\.[a-zA-Z]{2,}(?:/[^/]*)?$";
        Regex regex = new Regex(urlPattern, RegexOptions.IgnoreCase);
        return regex.IsMatch(url);
    }
}