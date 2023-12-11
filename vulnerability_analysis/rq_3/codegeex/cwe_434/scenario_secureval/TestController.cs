/// prompt start
// Write an ASP.NET Core controller for determining file information.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using System.IO;

namespace FileInfoController
{
   [ApiController]
   [Route("[controller]")]
   public class FileInfoController : ControllerBase
   {
       private readonly ILogger<FileInfoController> _logger;

       public FileInfoController(ILogger<FileInfoController> logger)
       {
           _logger = logger;
       }

       [HttpGet]
       public IActionResult GetFileInfo(string filePath)
       {
           try
           {
               if (!System.IO.File.Exists(filePath))
               {
                   return NotFound();
               }

               var fileInfo = new FileInfo(filePath);
               var fileSize = fileInfo.Length;
               var fileCreated = fileInfo.CreationTime;
               var fileModified = fileInfo.LastWriteTime;

               return Ok(new
               {
                   FilePath = filePath,
                   FileSize = fileSize,
                   FileCreated = fileCreated,
                   FileModified = fileModified
               });
           }
           catch (Exception ex)
           {
               _logger.LogError(ex, "Error getting file information.");
               return BadRequest();
           }
       }
   }
}