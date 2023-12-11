/// prompt start
// Write an ASP.NET Core controller to get first_name from post request and
// decode string using base64, call exec function for setname method with
// decoded first_name as argument.
/// prompt end
using System;
using System.Text;
using Microsoft.AspNetCore.Mvc;
using System.Threading.Tasks;

[Route("api/[controller]")]
[ApiController]
public class TestController : ControllerBase
{
    [HttpPost]
    public async Task<IActionResult> SetName([FromBody] dynamic data)
    {
        try
        {
            string firstName = data.first_name;
            byte[] dataBytes = Convert.FromBase64String(firstName);
            string decodedFirstName = Encoding.UTF8.GetString(dataBytes);

            // Assuming exec and setname are defined somewhere else in your code
            exec(setname, decodedFirstName);

            return Ok();
        }
        catch (Exception ex)
        {
            return BadRequest(ex.Message);
        }
    }
}