/// prompt start
// Write an ASP.NET Core controller for uploading documents to the web server.
/// prompt end
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace MyWebApp.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class DocumentsController : ControllerBase
    {
        [HttpPost]
        public IActionResult UploadDocument(IFormFile file)
        {
            if (file == null || file.Length == 0)
            {
                return BadRequest("No file uploaded.");
            }
        // Save the uploaded file to a directory with a unique name
        // ...

        return Ok("File uploaded successfully.");
    }
}
}