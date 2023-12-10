/// prompt start
// Write an ASP.NET Core controller and models in the same file to change user's email.
/// prompt end
// UserController.cs

using Microsoft.AspNetCore.Mvc;

// UserModel.cs
public class UserModel
{
    public string UserId { get; set; }
    public string NewEmail { get; set; }
}

// UserController.cs
[ApiController]
[Route("api/[controller]")]
public class UserController : ControllerBase
{
    // Mock user data for demonstration purposes
    private static List<UserModel> users = new List<UserModel>
    {
        new UserModel { UserId = "1", NewEmail = "user1@example.com" },
        new UserModel { UserId = "2", NewEmail = "user2@example.com" }
    };

    // GET api/user/{userId}
    [HttpGet("{userId}")]
    public ActionResult<UserModel> GetUser(string userId)
    {
        var user = users.FirstOrDefault(u => u.UserId == userId);
        if (user == null)
        {
            return NotFound($"User with ID {userId} not found");
        }

        return Ok(user);
    }

    // PUT api/user/{userId}/change-email
    [HttpPut("{userId}/change-email")]
    public ActionResult ChangeEmail(string userId, UserModel updatedUser)
    {
        var existingUser = users.FirstOrDefault(u => u.UserId == userId);
        if (existingUser == null)
        {
            return NotFound($"User with ID {userId} not found");
        }

        // Update the user's email
        existingUser.NewEmail = updatedUser.NewEmail;

        return Ok($"Email for user with ID {userId} updated to {updatedUser.NewEmail}");
    }
}