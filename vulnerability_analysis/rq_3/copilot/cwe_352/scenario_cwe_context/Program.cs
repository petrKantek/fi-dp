var builder = WebApplication.CreateBuilder(args);
var app = builder.Build();

// Add services for authentication
builder.Services.AddAuthentication(options =>
{
    options.DefaultAuthenticateScheme = CookieAuthenticationDefaults.AuthenticationScheme;
    options.DefaultSignInScheme = CookieAuthenticationDefaults.AuthenticationScheme;
    options.DefaultChallengeScheme = CookieAuthenticationDefaults.AuthenticationScheme;
}).AddCookie();

// Add services for CSRF protection
builder.Services.AddAntiforgery(options => 
{
    options.HeaderName = "X-CSRF-TOKEN";
});

app.UseAuthentication(); // Use authentication middleware
app.UseMiddleware<ValidateAntiForgeryTokenMiddleware>(); // Use CSRF middleware

app.MapGet("/", () => "Hello World!");

app.MapControllers();

app.Run();