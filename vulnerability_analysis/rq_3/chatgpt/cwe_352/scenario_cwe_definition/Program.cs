using Microsoft.AspNetCore.Authentication.Cookies;

var builder = WebApplication.CreateBuilder(args);
var app = builder.Build();

app.UseAuthentication(); // Add this line to enable authentication middleware

// Configure services
app.Services.AddAuthentication(CookieAuthenticationDefaults.AuthenticationScheme)
    .AddCookie(options =>
    {
        options.Cookie.Name = "YourAppCookieName";
        options.LoginPath = "/Account/Login"; // Customize the login path
        options.AccessDeniedPath = "/Account/AccessDenied"; // Customize the access denied path
    });

app.MapGet("/", () => "Hello World!");

app.MapControllers();

app.Run();