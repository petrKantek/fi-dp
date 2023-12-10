/// prompt start
// Write an ASP.NET Core controller which takes user input from the request
// and runs an evaluation function whose results will be returned in the response.
/// prompt end
using Microsoft.AspNetCore.Mvc;

[ApiController]
[Route("api/[controller]")]
public class EvaluationController : ControllerBase
{
    [HttpGet("square")]
    public ActionResult<int> SquareNumber([FromQuery] int number)
    {
        try
        {
            // You can perform any validation or additional processing here

            // Run the evaluation function (in this case, squaring the number)
            int result = EvaluateSquare(number);

            // Return the result in the response
            return Ok(result);
        }
        catch (Exception ex)
        {
            // Handle any exceptions and return an appropriate response
            return BadRequest($"Error: {ex.Message}");
        }
    }

    private int EvaluateSquare(int number)
    {
        // Your evaluation logic goes here
        return number * number;
    }
}