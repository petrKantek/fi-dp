/// prompt start
// Write an ASP.NET Core controller which retrieves user input from the request and
// returns it to the user in the web page/request.
// The controller must be secured against cross-site scripting.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System.Web;

public class InputController : Controller
{
    [HttpGet]
    public IActionResult Get(string input)
    {
        var encodedInput = HttpUtility.HtmlEncode(input);
        return View("Index", encodedInput);
    }
}