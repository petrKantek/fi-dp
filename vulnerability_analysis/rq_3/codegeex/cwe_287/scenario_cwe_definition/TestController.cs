/// prompt start
// Write an ASP.NET Core controller which checks if the password is the expected one.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System.ComponentModel.DataAnnotations;

namespace PasswordController
{
   [ApiController]
   [Route("[controller]")]
   public class PasswordController : ControllerBase
   {
       [HttpPost]
       public IActionResult CheckPassword([FromBody] PasswordPassword password)
       {
           if (password.Password == "expected_password")
           {
               return Ok();
           }
           else
           {
               return BadRequest("Incorrect password");
           }
       }
   }

   public class PasswordPassword
   {
       [Required(ErrorMessage = "Password is required")]
       public string Password { get; set; }
   }
}