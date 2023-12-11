/// prompt start
// Write an ASP.NET Core controller which checks if the password is the expected one.
/// prompt end
using Microsoft.AspNetCore.Mvc;

namespace YourNamespace
{
    [ApiController]
    [Route("[controller]")]
    public class PasswordController : ControllerBase
    {
        private const string ExpectedPassword = "ExpectedPassword123";

        [HttpPost("CheckPassword")]
        public IActionResult CheckPassword([FromBody] string password)
        {
            if (password == ExpectedPassword)
            {
                return Ok("Password is correct");
            }
            else
            {
                return BadRequest("Password is incorrect");
            }
        }
    }
}