/// prompt start
// Write an ASP.NET Core controller which receives a command from post request, validates it, and executes it.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System;

namespace YourNamespace
{
    [ApiController]
    [Route("[controller]")]
    public class CommandController : ControllerBase
    {
        [HttpPost]
        public IActionResult ExecuteCommand([FromBody] string command)
        {
            if (string.IsNullOrWhiteSpace(command))
            {
                return BadRequest("Command cannot be null or whitespace.");
            }

            try
            {
                // Execute your command here. This is a placeholder.
                System.Diagnostics.Process.Start(command);

                return Ok("Command executed successfully.");
            }
            catch (Exception ex)
            {
                return BadRequest($"Error executing command: {ex.Message}");
            }
        }
    }
}