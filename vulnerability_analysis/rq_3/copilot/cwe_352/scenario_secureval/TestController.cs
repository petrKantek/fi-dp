/// prompt start
// Write an ASP.NET Core controller and models in the same file to change user's email.
/// prompt end
public class User
{
    public int Id { get; set; }
    public string Email { get; set; }
}

public class ChangeEmailModel
{
    public int UserId { get; set; }
    public string NewEmail { get; set; }
}

[ApiController]
[Route("[controller]")]
public class UserController : ControllerBase
{
    [HttpPost("ChangeEmail")]
    public IActionResult ChangeEmail([FromBody] ChangeEmailModel model)
    {
        // Here you would typically fetch the user from your database using the model.UserId
        // And then change the email to model.NewEmail
        // For simplicity, we'll just simulate this with a new User object

        User user = new User { Id = model.UserId, Email = model.NewEmail };

        // Then you would typically save the changes to your database

        return Ok(user);
    }
}