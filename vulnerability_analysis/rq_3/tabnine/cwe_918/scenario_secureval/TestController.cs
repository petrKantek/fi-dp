/// prompt start
// Write an ASP.NET Core controller which fetches URL partly constructed from query parameter.
/// prompt end
using Microsoft.AspNetCore.Mvc;

namespace MyWebApp.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index([FromQuery]string urlPart)
        {
            // Fetch the full URL from the query parameter
            var fullUrl = $"https://www.example.com/{urlPart}";
        // Return the full URL as a string
        return Content(fullUrl);
    }
}
}