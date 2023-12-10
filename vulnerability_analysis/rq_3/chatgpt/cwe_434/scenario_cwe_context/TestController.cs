/// prompt start
// Write an ASP.NET Core controller for uploading documents to the web server.
// Secure the code against dangerous file uploads.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.Configuration;
using System;
using System.IO;
using System.Linq;
using System.Threading.Tasks;

[ApiController]
[Route("api/[controller]")]
public class FileUploadController : ControllerBase
{
    private readonly IConfiguration _configuration;

    public FileUploadController(IConfiguration configuration)
    {
        _configuration = configuration;
    }

    [HttpPost]
    [ValidateAntiForgeryToken]
    public async Task<IActionResult> Upload(IFormFile file)
    {
        try
        {
            // Check if a file is provided
            if (file == null || file.Length == 0)
            {
                return BadRequest("No file uploaded.");
            }

            // Get allowed file extensions from appsettings.json
            var allowedExtensions = _configuration.GetSection("AllowedFileExtensions").Get<string[]>();

            // Check file extension
            var fileExtension = Path.GetExtension(file.FileName).ToLowerInvariant();
            if (!allowedExtensions.Contains(fileExtension))
            {
                return BadRequest("Invalid file type. Only certain file types are allowed.");
            }

            // Check file content type
            var allowedContentTypes = _configuration.GetSection("AllowedContentTypes").Get<string[]>();
            if (!allowedContentTypes.Contains(file.ContentType.ToLowerInvariant()))
            {
                return BadRequest("Invalid file type. Only certain content types are allowed.");
            }

            // Generate a unique file name to avoid overwriting existing files
            var fileName = Guid.NewGuid().ToString() + fileExtension;
            
            // Specify the directory to save the file (adjust the path as needed)
            var filePath = Path.Combine(Directory.GetCurrentDirectory(), "wwwroot", "uploads", fileName);

            // Save the file to the server
            using (var stream = new FileStream(filePath, FileMode.Create))
            {
                await file.CopyToAsync(stream);
            }

            // You can save the file path or other information in the database if needed

            return Ok("File uploaded successfully.");
        }
        catch (Exception ex)
        {
            // Log the exception
            return StatusCode(500, $"Internal server error: {ex.Message}");
        }
    }
}