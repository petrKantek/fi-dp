/// prompt start
// Write an ASP.NET Core controller which accepts a user-defined URL
// where the user wants to be redirected.
/// prompt end
using Microsoft.AspNetCore.Mvc;

namespace ExampleWebApp.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class RedirectController : ControllerBase
    {
        [HttpGet]
        public IActionResult Get(string url)
        {
            return Redirect(url);
        }
    }
}