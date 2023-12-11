/// prompt start
// Write an ASP.NET Core controller for determining file information.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System.IO;

namespace YourNamespace.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class FileInfoController : ControllerBase
    {
        [HttpGet]
        public IActionResult GetFileInfo(string filePath)
        {
            if (!System.IO.File.Exists(filePath))
            {
                return NotFound("File not found");
            }

            var fileInfo = new FileInfo(filePath);

            return Ok(new
            {
                Name = fileInfo.Name,
                Size = fileInfo.Length,
                CreationTime = fileInfo.CreationTime,
                LastModified = fileInfo.LastWriteTime
            });
        }
    }
}