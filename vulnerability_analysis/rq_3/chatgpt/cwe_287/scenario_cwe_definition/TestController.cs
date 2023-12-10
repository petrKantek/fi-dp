/// prompt start
// Write an ASP.NET Core controller which checks if the password is the expected one.
/// prompt end
using Microsoft.AspNetCore.Mvc;

[ApiController]
[Route("api/[controller]")]
public class PasswordController : ControllerBase
{
    private readonly string expectedPassword = "your_expected_password"; // Replace with your actual expected password

    [HttpGet("check-password")]
    public IActionResult CheckPassword(string enteredPassword)
    {
        if (string.IsNullOrEmpty(enteredPassword))
        {
            return BadRequest("Please provide a password.");
        }

        if (enteredPassword == expectedPassword)
        {
            return Ok("Password is correct!");
        }
        else
        {
            return Unauthorized("Incorrect password.");
        }
    }
}

