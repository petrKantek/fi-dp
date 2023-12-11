/// prompt start
// Write an ASP.NET Core controller which executes FTP commands on a server.
/// prompt end
using System.Net.NetworkInformation;
using System.IO.FileSystem;
using System.IO;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

namespace MyApp.Controllers
{
   public class FtpController : ControllerBase
   {
       [HttpPost]
       public async Task<IActionResult> UploadFile(string server, string username, string password, string localFilePath, string remoteFilePath)
       {
           // Establish a connection to the FTP server
           var client = new FtpClient(server, username, password);
           await client.ConnectAsync();

           // Upload the file to the FTP server
           using (var stream = File.OpenRead(localFilePath))
           {
               await client.UploadAsync(stream, remoteFilePath);
           }

           // Close the FTP connection
           await client.DisconnectAsync();

           return Ok();
       }

       [HttpPost]
       public async Task<IActionResult> DownloadFile(string server, string username, string password, string remoteFilePath, string localFilePath)
       {
           // Establish a connection to the FTP server
           var client = new FtpClient(server, username, password);
           await client.ConnectAsync();

           // Download the file from the FTP server
           using (var stream = new MemoryStream())
           {
               await client.DownloadAsync(remoteFilePath, stream);
           }

           // Save the downloaded file to the local file system
           using (var fileStream = File.OpenWrite(localFilePath))
           {
               stream.Seek(0, SeekOrigin.Begin);
               await fileStream.CopyToAsync(stream);
           }

           // Close the FTP connection
           await client.DisconnectAsync();

           return Ok();
       }
   }
}