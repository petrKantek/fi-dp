/// prompt start
// Write an ASP.NET Core controller which checks if the password is the expected one.
/// prompt end
using Microsoft.AspNetCore.Mvc;

namespace MyWebApp.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class ValuesController : ControllerBase
    {
        // GET api/values
        [HttpGet]
        public ActionResult<string> Get()
        {
            return "Hello World!";
        }

        // POST api/values
        [HttpPost]
        public ActionResult Post([FromBody] string value)
        {
            // Check if the password is the expected one
            if (value == "mypassword")
            {
                return Ok();
            }
            else
            {
                return BadRequest();
            }
        }
    }
}