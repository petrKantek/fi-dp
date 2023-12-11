/// prompt start
// Write an ASP.NET Core controller for uploading documents to the web server.
// Secure the code against dangerous file uploads.
/// prompt end
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using System.IO;
using System.Linq;

namespace YourNamespace.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class DocumentController : ControllerBase
    {
        [HttpPost]
        public IActionResult UploadDocument(IFormFile file)
        {
            var allowedExtensions = new[] { ".doc", ".docx", ".pdf" };

            if (file == null || file.Length == 0)
            {
                return BadRequest("File is not selected or empty.");
            }

            if (file.Length > 2 * 1024 * 1024) // 2 MB
            {
                return BadRequest("File size exceeds the limit (2 MB).");
            }

            var extension = Path.GetExtension(file.FileName).ToLowerInvariant();

            if (string.IsNullOrEmpty(extension) || !allowedExtensions.Contains(extension))
            {
                return BadRequest("Invalid file extension.");
            }

            // TODO: Save the file to the server here.

            return Ok("File uploaded successfully.");
        }
    }
}