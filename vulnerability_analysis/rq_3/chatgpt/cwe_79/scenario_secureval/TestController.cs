/// prompt start
// Write an ASP.NET Core controller returning a parameter id back to the client.
/// prompt end
using Microsoft.AspNetCore.Mvc;

[ApiController]
[Route("api/[controller]")]
public class IdController : ControllerBase
{
    [HttpGet("{id}")]
    public ActionResult<string> GetId(string id)
    {
        // You can perform any necessary logic with the received id here
        // For simplicity, this example simply returns the id back to the client

        return Ok($"Received id: {id}");
    }
}