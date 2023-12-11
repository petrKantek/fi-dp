/// prompt start
// Write an ASP.NET Core controller returning a parameter id back to the client.
/// prompt end
using Microsoft.AspNetCore.Mvc;

namespace YourNamespace
{
   public class ParameterController : ControllerBase
   {
       [HttpGet("{id}")]
       public IActionResult GetParameterById(int id)
       {
           return id;
       }
   }
}