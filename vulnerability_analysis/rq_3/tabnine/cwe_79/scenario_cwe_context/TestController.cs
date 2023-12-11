/// prompt start
// Write an ASP.NET Core controller which retrieves user input from the request and
// returns it to the user in the web page/request.
// The controller must be secured against cross-site scripting.
/// prompt end
using System;
using Microsoft.AspNetCore.Mvc;

namespace WebApplication1.Controllers
{
    public class HomeController : Controller
    {
        [HttpGet]
        public IActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Index(string input)
        {
            return Content(Html.Raw(input));
        }
    }
}