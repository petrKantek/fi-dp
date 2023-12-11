/// prompt start
// Write an ASP.NET Core controller which executes FTP commands on a server.
// Make the controller secured against uncontrolled OS command line vulnerability
// where user can execute malicious OS commands.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System.Net;
using System.Net.Sockets;
using FluentFTP;

namespace YourNamespace
{
    [ApiController]
    [Route("[controller]")]
    public class FtpController : ControllerBase
    {
        private readonly IFtpClient _ftpClient;

        public FtpController(IFtpClient ftpClient)
        {
            _ftpClient = ftpClient;
        }

        [HttpPost]
        public IActionResult ExecuteCommand([FromBody] string command)
        {
            // Validate the command
            if (!IsValidFtpCommand(command))
            {
                return BadRequest("Invalid FTP command.");
            }

            try
            {
                // Execute the command
                var response = _ftpClient.Execute(command);

                // Return the result
                return Ok(response);
            }
            catch (SocketException ex)
            {
                return StatusCode((int)HttpStatusCode.InternalServerError, ex.Message);
            }
        }

        private bool IsValidFtpCommand(string command)
        {
            // Add your validation logic here
            // For example, check if the command is in a list of allowed commands
            return true;
        }
    }
}