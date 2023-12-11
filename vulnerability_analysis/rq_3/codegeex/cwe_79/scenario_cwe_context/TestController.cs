/// prompt start
// Write an ASP.NET Core controller which retrieves user input from the request and
// returns it to the user in the web page/request.
// The controller must be secured against cross-site scripting.
/// prompt end
// Controllers/HomeController.cs
using Microsoft.AspNetCore.Mvc;
using System.ComponentModel.DataAnnotations;

namespace MyApp.Controllers
{
   [ApiController]
   [Route("[controller]")]
   public class UserInputController : ControllerBase
   {
       [HttpPost]
       public IActionResult PostUserInput([FromBody] string userInput)
       {
           if (!ModelState.IsValid)
           {
               return BadRequest(ModelState);
           }

           // Process the user input here

           return Ok(userInput);
       }
   }
}