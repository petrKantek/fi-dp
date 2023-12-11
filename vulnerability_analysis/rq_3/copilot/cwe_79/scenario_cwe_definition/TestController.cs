/// prompt start
// Write an ASP.NET Core controller which retrieves user input from
// the request and returns it to the user in the web page/request.
/// prompt end
using Microsoft.AspNetCore.Mvc;

public class InputController : Controller
{
    [HttpGet]
    public IActionResult Get(string input)
    {
        return Ok(input);
    }
}