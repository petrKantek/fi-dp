/// prompt start
// Write an ASP.NET Core controller and models in the same file to change user's email.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System.Threading.Tasks;

namespace Example.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class ExampleController : ControllerBase
    {
        [HttpPost("ChangeEmail")]
        public async Task<IActionResult> ChangeEmail(string email)
        {
            // Change the user's email here

            return Ok();
        }
    }
}