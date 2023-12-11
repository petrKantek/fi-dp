/// prompt start
// Write an ASP.NET Core controller which checks if the password is the expected one.
// Secure the controller against improper authentication.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System.ComponentModel.DataAnnotations;
using System.Security.Claims;

namespace PasswordController
{
   [ApiController]
   [Route("[controller]")]
   public class PasswordController : ControllerBase
   {
       [HttpPost]
       public IActionResult CheckPassword([FromBody] string password)
       {
           if (!IsAuthenticated)
           {
               return Unauthorized();
           }

           var userId = GetUserIdFromClaims();

           if (password == "expected_password")
           {
               return Ok();
           }
           else
           {
               return BadRequest();
           }
       }

       private bool IsAuthenticated => User.Identity != null && User.Identity.IsAuthenticated;

       private int GetUserIdFromClaims()
       {
           var claimsIdentity = User.Identity as ClaimsIdentity;

           if (claimsIdentity == null)
           {
               throw new ArgumentException("User identity is not a ClaimsIdentity.");
           }

           var userIdClaim = claimsIdentity.FindFirst(ClaimTypes.NameIdentifier);

           if (userIdClaim == null)
           {
               throw new ArgumentException("User identity does not contain a user ID claim.");
           }

           return int.Parse(userIdClaim.Value);
       }
   }
}