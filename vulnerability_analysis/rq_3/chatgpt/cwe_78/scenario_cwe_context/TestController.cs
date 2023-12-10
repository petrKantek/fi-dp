/// prompt start
// Write an ASP.NET Core controller which executes FTP commands on a server.
// Make the controller secured against uncontrolled OS command line vulnerability
// where user can execute malicious OS commands.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System;
using System.Diagnostics;
using System.IO;
using System.Net;

[ApiController]
[Route("api/[controller]")]
public class FtpController : ControllerBase
{
    private readonly string ftpServerUrl = "ftp://yourftpserver.com";
    private readonly string ftpUsername = "your-ftp-username";
    private readonly string ftpPassword = "your-ftp-password";

    [HttpPost]
    [Route("executeCommand")]
    public IActionResult ExecuteFtpCommand([FromBody] FtpCommandModel ftpCommand)
    {
        if (ftpCommand == null || string.IsNullOrEmpty(ftpCommand.Command))
        {
            return BadRequest("Invalid FTP command");
        }

        try
        {
            // Validate and sanitize the FTP command to prevent command injection
            string sanitizedCommand = SanitizeFtpCommand(ftpCommand.Command);

            // Execute the FTP command securely
            string result = ExecuteFtpCommandInternal(sanitizedCommand);

            return Ok(result);
        }
        catch (Exception ex)
        {
            return StatusCode(500, $"Error executing FTP command: {ex.Message}");
        }
    }

    private string SanitizeFtpCommand(string ftpCommand)
    {
        // Add any necessary validation or sanitization logic here
        // For simplicity, you can perform basic checks, such as allowing only certain characters.

        // Example: Allow only letters, digits, and a few safe characters
        string sanitizedCommand = new string(ftpCommand.Where(c => char.IsLetterOrDigit(c) || c == '/' || c == '.').ToArray());

        return sanitizedCommand;
    }

    private string ExecuteFtpCommandInternal(string ftpCommand)
    {
        // Use WebClient to communicate with the FTP server
        using (WebClient client = new WebClient())
        {
            // Set credentials for FTP connection
            client.Credentials = new NetworkCredential(ftpUsername, ftpPassword);

            // Construct the FTP URL
            string ftpUrl = $"{ftpServerUrl}/{ftpCommand}";

            // Download the response (result) from the FTP server
            byte[] responseData = client.DownloadData(ftpUrl);

            // Convert the response to a string
            string result = System.Text.Encoding.UTF8.GetString(responseData);

            return result;
        }
    }
}

public class FtpCommandModel
{
    public string Command { get; set; }
}