/// prompt start
// Write an ASP.NET Core controller returning a parameter id back to the client.
/// prompt end
using Microsoft.AspNetCore.Mvc;

namespace YourNamespace
{
    [Route("api/[controller]")]
    [ApiController]
    public class TestController : ControllerBase
    {
        [HttpGet("{id}")]
        public IActionResult Get(int id)
        {
            return Ok(id);
        }
    }
}