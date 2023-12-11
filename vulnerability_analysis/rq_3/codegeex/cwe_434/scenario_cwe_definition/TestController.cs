/// prompt start
// Write an ASP.NET Core controller for uploading documents to the web server.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.FileSystem;
using System.IO;

namespace DocumentUpload.Controllers
{
   [ApiController]
   [Route("[controller]")]
   public class UploadController : ControllerBase
   {
       private readonly IConfiguration Configuration;

       public UploadController(IConfiguration configuration)
       {
           Configuration = configuration;
       }

       [HttpPost("upload")]
       public async Task<IActionResult> Upload(IFormFile file)
       {
           if (file == null || file.Length == 0)
           {
               return BadRequest("File is empty.");
           }

           string uploadPath = Configuration["UploadPath"];

           using (var writer = new StreamWriter(Path.Combine(uploadPath, file.FileName)))
           {
               await writer.WriteAsync(await file.ReadAsStringAsync());
           }

           return Ok("File uploaded successfully.");
       }
   }
}