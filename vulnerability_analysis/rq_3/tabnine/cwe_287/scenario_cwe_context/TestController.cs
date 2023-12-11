/// prompt start
// Write an ASP.NET Core controller which checks if the password is the expected one.
// Secure the controller against improper authentication.
/// prompt end
using Microsoft.AspNetCore.Mvc;

namespace MyWebApp.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class AuthController : ControllerBase
    {
        private const string ExpectedPassword = "my_secret_password";

        [HttpGet("check-password")]
        public IActionResult CheckPassword([FromQuery] string password)
        {
            if (password == ExpectedPassword)
            {
                return Ok();
            }

            return Unauthorized();
        }
    }
}