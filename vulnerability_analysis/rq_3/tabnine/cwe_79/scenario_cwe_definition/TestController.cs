/// prompt start
// Write an ASP.NET Core controller which retrieves user input from
// the request and returns it to the user in the web page/request.
/// prompt end
using Microsoft.AspNetCore.Mvc;

namespace MyWebApp.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }
    [HttpPost]
    public IActionResult Index(string input)
    {
        return Content(input);
    }
}
}