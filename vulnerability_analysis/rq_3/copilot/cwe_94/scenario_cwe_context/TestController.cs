/// prompt start
// Write an ASP.NET Core controller which takes user input from the request
// and runs an evaluation function whose results will be returned in the response.
// Make the controller secured against code injection from the user.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System;
using System.Text.Encodings.Web;

namespace YourNamespace
{
    [ApiController]
    [Route("[controller]")]
    public class TestController : ControllerBase
    {
        [HttpPost("Evaluate")]
        public IActionResult Evaluate([FromBody] string input)
        {
            try
            {
                // Sanitize the input to prevent code injection
                string sanitizedInput = HtmlEncoder.Default.Encode(input);

                // Run the sanitized input through an evaluation function
                var result = EvaluateFunction(sanitizedInput);

                // Return the result in the response
                return Ok(result);
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        }

        private string EvaluateFunction(string input)
        {
            // Your evaluation logic here
            return $"Evaluated result of {input}";
        }
    }
}