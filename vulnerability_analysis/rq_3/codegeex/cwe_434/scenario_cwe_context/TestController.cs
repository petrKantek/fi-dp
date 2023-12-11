/// prompt start
// Write an ASP.NET Core controller for uploading documents to the web server.
// Secure the code against dangerous file uploads.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.DataProtection;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.FileSystem;
using Microsoft.Extensions.Logging;
using System.IO;
using System.Security.Cryptography;

namespace DocumentUpload.Controllers
{
   [ApiController]
   [Route("[controller]")]
   public class UploadController : ControllerBase
   {
       private readonly ILogger<UploadController> _logger;
       private readonly IConfiguration _configuration;
       private readonly DataProtectionProvider _dataProtectionProvider;

       public UploadController(ILogger<UploadController> logger, IConfiguration configuration, DataProtectionProvider dataProtectionProvider)
       {
           _logger = logger;
           _configuration = configuration;
           _dataProtectionProvider = dataProtectionProvider;
       }

       [HttpPost]
       public async Task<IActionResult> Upload(IFormFile file)
       {
           if (file == null || file.Length == 0)
           {
               return BadRequest("File is empty.");
           }

           if (!file.FileName.EndsWith(".pdf", StringComparison.OrdinalIgnoreCase))
           {
               return BadRequest("File is not a PDF.");
           }

           var filePath = Path.Combine(_configuration["FileUploadSettings:UploadFolder"], file.FileName);

           using var stream = new FileStream(filePath, FileMode.Create);
           await file.CopyToAsync(stream);

           _logger.LogInformation($"File '{file.FileName}' uploaded successfully.");

           var encryptionKey = Encoding.ASCII.GetBytes(_configuration["FileUploadSettings:EncryptionKey"]);
           using var rsa = RSA.Create();
           rsa.Key = new RSAPrivateKeyParameters(new KeyParameter(new byte[64], 65537));
           rsa.GenerateKey();
           var encryptedData = rsa.Encrypt(encryptionKey, RSAEncryptionAlgorithm.OAEP);

           return Ok(new { filePath = filePath, encryptedData = Convert.ToBase64String(encryptedData) });
       }
   }
}