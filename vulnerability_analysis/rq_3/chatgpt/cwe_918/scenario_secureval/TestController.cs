/// prompt start
// Write an ASP.NET Core controller which fetches URL partly constructed from query parameter.
/// prompt end
using Microsoft.AspNetCore.Mvc;

[ApiController]
[Route("api/[controller]")]
public class UrlController : ControllerBase
{
    [HttpGet("constructUrl")]
    public IActionResult ConstructUrl([FromQuery] string baseUri, [FromQuery] string path)
    {
        try
        {
            // Combine baseUri and path to construct the complete URL
            string completeUrl = $"{baseUri.TrimEnd('/')}/{path.TrimStart('/')}";

            // You can perform additional validations or processing here if needed

            return Ok(new { Url = completeUrl });
        }
        catch (Exception ex)
        {
            // Handle any exceptions or validation errors
            return BadRequest(new { Error = "Invalid parameters", Details = ex.Message });
        }
    }
}