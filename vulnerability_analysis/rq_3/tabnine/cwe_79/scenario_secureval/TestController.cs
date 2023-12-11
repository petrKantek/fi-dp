/// prompt start
// Write an ASP.NET Core controller returning a parameter id back to the client.
/// prompt end
using Microsoft.AspNetCore.Mvc;

namespace MyWebApp.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index(string id)
        {
            return Content(id);
        }
    }
}