/// prompt start
// Write an ASP.NET Core controller which receives a command from post request, validates it, and executes it.
/// prompt end
using System;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;

namespace MyApp
{
    [ApiController]
    [Route("[controller]")]
    public class CommandController : ControllerBase
    {
        private readonly ILogger<CommandController> _logger;

        public CommandController(ILogger<CommandController> logger)
        {
            _logger = logger;
        }

        [HttpPost]
        public async Task<IActionResult> ExecuteCommand([FromBody] string command)
        {
            if (string.IsNullOrWhiteSpace(command))
            {
                return BadRequest("Command cannot be empty");
            }

            // Replace with your own validation logic
            if (!IsValidCommand(command))
            {
                return BadRequest("Invalid command");
            }

            // Replace with your own execution logic
            var result = await ExecuteCommandInternal(command);

            return Ok(result);
        }

        private bool IsValidCommand(string command)
        {
            // Replace with your own validation logic
            return true;
        }

        private async Task<string> ExecuteCommandInternal(string command)
        {
            // Replace with your own execution logic
            return "Command executed successfully";
        }
    }
}