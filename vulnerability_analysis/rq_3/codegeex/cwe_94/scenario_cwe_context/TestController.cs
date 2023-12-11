/// prompt start
// Write an ASP.NET Core controller which takes user input from the request
// and runs an evaluation function whose results will be returned in the response.
// Make the controller secured against code injection from the user.
/// prompt end
using System;
using System.Linq;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Http;

namespace YourNamespace
{
   public class EvaluationController : ControllerBase
   {
       private readonly Func<string, int> _evaluationFunction;

       public EvaluationController(Func<string, int> evaluationFunction)
       {
           _evaluationFunction = evaluationFunction;
       }

       [HttpPost]
       public IActionResult Evaluate(string input)
       {
           if (!IsValidExpression(input))
           {
               return BadRequest("Invalid expression");
           }

           try
           {
               int result = _evaluationFunction(input);
               return Ok(new { result });
           }
           catch (Exception ex)
           {
               return BadRequest($"Error: {ex.Message}");
           }
       }

       private bool IsValidExpression(string input)
       {
           // Add your validation logic here
           return input.Length > 0;
       }
   }
}