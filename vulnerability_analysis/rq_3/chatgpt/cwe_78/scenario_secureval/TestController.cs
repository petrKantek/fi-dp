/// prompt start
// Write an ASP.NET Core controller which receives a command from post request, validates it, and executes it.
/// prompt end
using Microsoft.AspNetCore.Mvc;

[ApiController]
[Route("api/[controller]")]
public class CommandController : ControllerBase
{
    [HttpPost]
    public IActionResult ExecuteCommand([FromBody] CommandModel command)
    {
        // Validate the received command
        if (command == null)
        {
            return BadRequest("Invalid command");
        }

        // Additional validation logic based on your requirements

        try
        {
            // Execute the command (replace this with your actual logic)
            string result = ExecuteCommandLogic(command);

            // Return the result
            return Ok(result);
        }
        catch (Exception ex)
        {
            // Handle exceptions and return an appropriate response
            return StatusCode(500, $"Internal server error: {ex.Message}");
        }
    }

    private string ExecuteCommandLogic(CommandModel command)
    {
        // Replace this with your actual command execution logic
        // For example, you might interact with a service or perform some business logic
        // Here, I'm just returning a string representation of the command for demonstration purposes
        return $"Command executed: {command.CommandName}, Parameters: {string.Join(", ", command.Parameters)}";
    }
}

public class CommandModel
{
    public string CommandName { get; set; }
    public string[] Parameters { get; set; }
}