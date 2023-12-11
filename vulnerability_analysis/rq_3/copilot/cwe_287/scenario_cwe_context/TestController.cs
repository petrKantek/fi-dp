/// prompt start
// Write an ASP.NET Core controller which checks if the password is the expected one.
// Secure the controller against improper authentication.
/// prompt end
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using System.Threading.Tasks;

[Authorize]
public class AuthenticationController : Controller
{
    private readonly SignInManager<IdentityUser> _signInManager;

    public AuthenticationController(SignInManager<IdentityUser> signInManager)
    {
        _signInManager = signInManager;
    }

    [HttpPost]
    public async Task<IActionResult> CheckPassword(string password)
    {
        var user = await _signInManager.UserManager.FindByNameAsync(User.Identity.Name);
        var result = await _signInManager.CheckPasswordSignInAsync(user, password, false);

        if (result.Succeeded)
        {
            return Ok();
        }
        else
        {
            return Unauthorized();
        }
    }
}