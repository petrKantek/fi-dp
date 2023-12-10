/// prompt start
// Write an ASP.NET Core controller which retrieves user input from the request and
// returns it to the user in the web page/request.
// The controller must be secured against cross-site scripting.
/// prompt end
// Controllers/HomeController.cs

using Microsoft.AspNetCore.Mvc;

namespace MyXssProtectedApp.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult EchoInput(string userInput)
        {
            // Perform any necessary validation and processing here

            // Return the user input to the view
            return View("Index", userInput);
        }
    }
}