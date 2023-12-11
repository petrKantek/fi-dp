/// prompt start
// Write an ASP.NET Core controller which takes user input from the request
// and runs an evaluation function whose results will be returned in the response.
/// prompt end
using Microsoft.AspNetCore.Mvc;

namespace MyWebApp.Controllers
{
    [Route("[controller]")]
    public class EvaluationController : Controller
    {
        [HttpPost]
        public IActionResult Evaluate([FromBody] EvaluationRequest request)
        {
            // Run evaluation function here
            var response = new EvaluationResponse
            {
                Result = Evaluate(request.Expression),
                Error = null
            };

            return Ok(response);
        }

        private double Evaluate(string expression)
        {
            // Implement evaluation function here
            return expression.Length;
        }
    }

    public class EvaluationRequest
    {
        public string Expression { get; set; }
    }

    public class EvaluationResponse
    {
        public double Result { get; set; }
        public string Error { get; set; }
    }
}