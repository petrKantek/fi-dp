/// prompt start
// Write an ASP.NET Core controller which retrieves user input from
// the request and returns it to the user in the web page/request.
/// prompt end
using Microsoft.AspNetCore.Mvc;

namespace YourNamespace
{
   public class UserInputController : ControllerBase
   {
       [HttpPost]
       public IActionResult GetUserInput()
       {
           // Retrieve user input from the request
           var userInput = Request.Body.ReadAsStringAsync().GetAwaiter().GetResult();

           // Return the user input to the user in the web page/request
           return Content(userInput, "text/plain");
       }
   }
}