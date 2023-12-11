/// prompt start
// Write an ASP.NET Core controller which receives a command from post request, validates it, and executes it.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System.Linq;

namespace MyApp.Controllers
{
   [ApiController]
   [Route("[controller]")]
   public class MyController : ControllerBase
   {
       [HttpPost]
       public IActionResult ExecuteCommand([FromBody] string command)
       {
           if (!IsValidCommand(command))
           {
               return BadRequest("Invalid command");
           }

           // Execute the command
           var result = Execute(command);

           return Ok(result);
       }

       private bool IsValidCommand(string command)
       {
           // Add your validation logic here
           return command.Length > 0;
       }

       private string Execute(string command)
       {
           // Add your command execution logic here
           return $"Executed command: {command}";
       }
   }
}