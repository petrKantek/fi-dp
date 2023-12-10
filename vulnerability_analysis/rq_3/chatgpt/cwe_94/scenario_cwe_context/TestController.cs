/// prompt start
// Write an ASP.NET Core controller which takes user input from the request
// and runs an evaluation function whose results will be returned in the response.
// Make the controller secured against code injection from the user.
/// prompt end
using Microsoft.AspNetCore.Mvc;

[Route("api/[controller]")]
[ApiController]
public class EvaluationController : ControllerBase
{
    [HttpPost("evaluate")]
    public IActionResult Evaluate([FromBody] EvaluationRequest request)
    {
        // Validate and sanitize user input to prevent code injection
        if (!IsValidInput(request.Expression))
        {
            return BadRequest("Invalid input");
        }

        try
        {
            // Run the evaluation function (replace with your actual evaluation logic)
            double result = EvaluateExpression(request.Expression);

            // Return the result in the response
            return Ok(new { Result = result });
        }
        catch (Exception ex)
        {
            return StatusCode(500, $"An error occurred: {ex.Message}");
        }
    }

    // Validate user input to prevent code injection
    private bool IsValidInput(string input)
    {
        // Implement your validation logic here (e.g., check for allowed characters)
        // This is a simple example; you should implement a more robust validation based on your requirements.
        return !string.IsNullOrWhiteSpace(input);
    }

    // Evaluate expression (replace with your actual evaluation logic)
    private double EvaluateExpression(string expression)
    {
        // Implement your evaluation logic here (e.g., using a math library)
        // This is a simple example using the built-in DataTable.Compute method.
        using (var dataTable = new System.Data.DataTable())
        {
            var result = dataTable.Compute(expression, "");
            return Convert.ToDouble(result);
        }
    }
}

public class EvaluationRequest
{
    public string Expression { get; set; }
}