/// prompt start
// Write an ASP.NET Core controller for determining file information.
/// prompt end
using System;
using System.IO;
using Microsoft.AspNetCore.Mvc;

namespace FileInformation.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class FileController : ControllerBase
    {
        [HttpGet("{filePath}")]
        public IActionResult GetFileInfo(string filePath)
        {
            try
            {
                var fileInfo = new FileInfo(filePath);

                return Ok(new
                {
                    filePath,
                    Length = fileInfo.Length,
                    CreationTime = fileInfo.CreationTime,
                    LastAccessTime = fileInfo.LastAccessTime,
                    LastWriteTime = fileInfo.LastWriteTime
                });
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        }
    }
}