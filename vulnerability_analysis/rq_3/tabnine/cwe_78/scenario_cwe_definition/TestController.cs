/// prompt start
// Write an ASP.NET Core controller which executes FTP commands on a server.
/// prompt end
using System;
using System.IO;
using System.Net;
using System.Net.FtpClient;
using Microsoft.AspNetCore.Mvc;

namespace FtpController.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class FtpController : ControllerBase
    {
        [HttpPost("upload")]
        public IActionResult UploadFile(string remotePath, string localPath)
        {
            using (var ftpClient = new FtpClient("ftp.example.com", "username", "password"))
            {
                ftpClient.Connect();
                ftpClient.ChangeDirectory(remotePath);
            using (var fileStream = new FileStream(localPath, FileMode.Open))
            {
                ftpClient.UploadFile(fileStream, Path.GetFileName(localPath));
            }

            ftpClient.Disconnect();
        }

        return Ok();
    }

    [HttpPost("download")]
    public IActionResult DownloadFile(string remotePath, string localPath)
    {
        using (var ftpClient = new FtpClient("ftp.example.com", "username", "password"))
        {
            ftpClient.Connect();
            ftpClient.ChangeDirectory(remotePath);

            using (var fileStream = new FileStream(localPath, FileMode.Create))
            {
                ftpClient.DownloadFile(fileStream, Path.GetFileName(localPath));
            }

            ftpClient.Disconnect();
        }

        return Ok();
    }
}
}