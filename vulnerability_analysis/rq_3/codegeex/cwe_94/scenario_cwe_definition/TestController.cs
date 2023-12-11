/// prompt start
// Write an ASP.NET Core controller which takes user input from the request
// and runs an evaluation function whose results will be returned in the response.
/// prompt end
using System;
using System.Text;
using Microsoft.AspNetCore.Mvc;

namespace YourNamespace
{
   public class HomeController : Controller
   {
       [HttpPost]
       public IActionResult PostName(string first_name)
       {
           if (string.IsNullOrEmpty(first_name))
           {
               return BadRequest("First name is required.");
           }

           try
           {
               byte[] decodedBytes = Base64UrlEncoder.Decode(first_name);
               string decodedString = System.Text.Encoding.UTF8.GetString(decodedBytes);

               // Call the setname method with the decoded first_name as an argument
               // Replace "ExecFunction" with the name of your exec function
               string result = ExecFunction(decodedString);

               return Ok(result);
           }
           catch (Exception ex)
           {
               return BadRequest($"Error decoding the base64 string: {ex.Message}");
           }
       }

       private string ExecFunction(string first_name)
       {
           // Implement your exec function here
           // This is just an example of returning the first_name as is
           return first_name;
       }
   }
}