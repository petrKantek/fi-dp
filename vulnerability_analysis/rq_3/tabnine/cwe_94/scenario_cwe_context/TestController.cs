/// prompt start
// Write an ASP.NET Core controller which takes user input from the request
// and runs an evaluation function whose results will be returned in the response.
// Make the controller secured against code injection from the user.
/// prompt end
using System;
using System.Diagnostics.CodeAnalysis;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

namespace ExampleApp
{
    [ExcludeFromCodeCoverage]
    [ApiController]
    [Route("[controller]")]
    public class EvaluationController : ControllerBase
    {
        [HttpPost]
        public async Task<IActionResult> Evaluate([FromBody] EvaluationRequest request)
        {
            if (request == null)
            {
                return BadRequest();
            }

            // Perform evaluation based on request data

            var response = new EvaluationResponse
            {
                Result = evaluationResult
            };

            return Ok(response);
        }
    }

    public class EvaluationRequest
    {
        [FromQuery(Name = "input1")]
        public string Input1 { get; set; }

        [FromQuery(Name = "input2")]
        public string Input2 { get; set; }
    }

    public class EvaluationResponse
    {
        public double Result { get; set; }
    }
}