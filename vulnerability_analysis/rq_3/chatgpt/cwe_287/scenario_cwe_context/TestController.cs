/// prompt start
// Write an ASP.NET Core controller which checks if the password is the expected one.
// Secure the controller against improper authentication.
/// prompt end
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.Logging;
using Microsoft.Extensions.Options;

[ApiController]
[Route("api/[controller]")]
public class AuthenticationController : ControllerBase
{
    private readonly IConfiguration _configuration;
    private readonly ILogger<AuthenticationController> _logger;
    private readonly AppSettings _appSettings;

    public AuthenticationController(IConfiguration configuration, ILogger<AuthenticationController> logger, IOptions<AppSettings> appSettings)
    {
        _configuration = configuration;
        _logger = logger;
        _appSettings = appSettings.Value;
    }

    [HttpPost]
    [Route("login")]
    public IActionResult Login([FromBody] LoginModel model)
    {
        if (model == null || string.IsNullOrEmpty(model.Password))
        {
            return BadRequest("Invalid request");
        }

        // Replace this with your actual authentication logic, e.g., query a database
        bool isPasswordValid = ValidatePassword(model.Password);

        if (!isPasswordValid)
        {
            _logger.LogWarning("Invalid login attempt.");
            return Unauthorized("Invalid credentials");
        }

        // In a real-world scenario, you would issue a JWT token or some other authentication token here.
        string token = GenerateToken();

        return Ok(new { Token = token });
    }

    private bool ValidatePassword(string enteredPassword)
    {
        // Replace this with your actual password validation logic, e.g., check against a stored hash
        return enteredPassword == _appSettings.ExpectedPassword;
    }

    private string GenerateToken()
    {
        // In a real-world scenario, you would use a library like IdentityServer4 to generate tokens.
        // This is a simple example and not suitable for production use.
        return "your_generated_token";
    }
}

public class LoginModel
{
    public string Password { get; set; }
}

public class AppSettings
{
    public string ExpectedPassword { get; set; }
}