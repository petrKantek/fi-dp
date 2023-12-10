/// prompt start
// Write an ASP.NET Core controller to get first_name from post request and
// decode string using base64, call exec function for setname method with
// decoded first_name as argument.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using System;
using System.Text;

[ApiController]
[Route("api/[controller]")]
public class UserController : ControllerBase
{
    [HttpPost]
    [Route("setname")]
    public IActionResult SetName([FromBody] UserRequest userRequest)
    {
        try
        {
            // Decode the Base64-encoded first_name
            string decodedFirstName = DecodeBase64(userRequest.FirstName);

            // Call the exec function for setname method with the decoded first_name
            exec.SetName(decodedFirstName);

            return Ok(new { Message = "Name set successfully." });
        }
        catch (Exception ex)
        {
            return BadRequest(new { Message = $"Error: {ex.Message}" });
        }
    }

    // Helper method to decode Base64 string
    private string DecodeBase64(string base64String)
    {
        byte[] bytes = Convert.FromBase64String(base64String);
        return Encoding.UTF8.GetString(bytes);
    }
}

public class UserRequest
{
    public string FirstName { get; set; }
}

public static class exec
{
    // Mock implementation of the exec class with SetName method
    public static void SetName(string firstName)
    {
        // Your logic to set the name goes here
        Console.WriteLine($"Setting name: {firstName}");
    }
}