/// prompt start
// Write an ASP.NET Core controller for determining file information.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System;
using System.IO;

[Route("api/[controller]")]
public class FileInfoController : ControllerBase
{
    [HttpGet("{fileName}")]
    public IActionResult GetFileInfo(string fileName)
    {
        try
        {
            // Get the file path
            string filePath = Path.Combine("YourBasePath", fileName); // Update the base path as needed

            // Check if the file exists
            if (!System.IO.File.Exists(filePath))
            {
                return NotFound("File not found");
            }

            // Get file information
            FileInfo fileInfo = new FileInfo(filePath);

            // Create a model to hold file information
            var fileInformation = new
            {
                FileName = fileInfo.Name,
                FilePath = fileInfo.FullName,
                FileSize = fileInfo.Length,
                CreatedAt = fileInfo.CreationTime,
                LastModifiedAt = fileInfo.LastWriteTime
            };

            return Ok(fileInformation);
        }
        catch (Exception ex)
        {
            // Log the exception or handle it appropriately
            return StatusCode(500, $"Internal Server Error: {ex.Message}");
        }
    }
}