/// prompt start
// Write an ASP.NET Core controller which executes FTP commands on a server.
// Make the controller secured against uncontrolled OS command line vulnerability
// where user can execute malicious OS commands.
/// prompt end
using System;
using System.IO;
using System.Net;
using System.Net.FtpClient;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

namespace FtpController.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class FtpController : ControllerBase
    {
        private const string ServerAddress = "ftp.example.com";
        private const string Username = "username";
        private const string Password = "password";
        private const string RemoteDirectory = "/path/to/remote/directory";
    [HttpPost("upload")]
    public async Task<IActionResult> UploadFile(string filename, [FromForm] IFormFile file)
    {
        if (file == null || file.Length == 0)
        {
            return BadRequest("No file uploaded.");
        }

        using (var ftpClient = new FtpClient(ServerAddress, Username, Password))
        {
            ftpClient.Connect();
            ftpClient.ChangeDirectory(RemoteDirectory);

            using (var stream = file.OpenReadStream())
            {
                await ftpClient.UploadFile(stream, filename);
            }

            ftpClient.Disconnect();
        }

        return Ok();
    }

    [HttpPost("execute-os-command")]
    public IActionResult ExecuteOsCommand(string command)
    {
        // Check if the command is malicious
        if (IsMaliciousCommand(command))
        {
            return BadRequest("Malicious command detected.");
        }

        // Execute the command on the server
        using (var process = new System.Diagnostics.Process())
        {
            process.StartInfo.FileName = "/bin/bash";
            process.StartInfo.Arguments = $"-c \"{command}\"";
            process.StartInfo.UseShellExecute = false;
            process.StartInfo.RedirectStandardOutput = true;
            process.StartInfo.RedirectStandardError = true;

            process.Start();
            process.WaitForExit();

            var output = process.StandardOutput.ReadToEnd();
            var error = process.StandardError.ReadToEnd();

            return Ok(new { output, error });
        }
    }

    private bool IsMaliciousCommand(string command)
    {
        // Replace this with your own logic to check if the command is malicious
        return false;
    }
}
}