using Microsoft.AspNetCore.Authentication.Cookies;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.DependencyInjection;

var builder = WebApplication.CreateBuilder(args);
var app = builder.Build();

// Configure services
app.Services.AddAuthentication(CookieAuthenticationDefaults.AuthenticationScheme)
    .AddCookie(options =>
    {
        options.Cookie.Name = "YourAppCookieName";
        options.LoginPath = "/Account/Login"; // Customize the login path
        options.AccessDeniedPath = "/Account/AccessDenied"; // Customize the access denied path
    });

app.Services.AddAntiforgery(options =>
{
    options.HeaderName = "X-CSRF-TOKEN"; // Customize the header name
});

app.Services.AddControllersWithViews();

// Configure middleware
app.UseAuthentication();
app.UseAuthorization();

app.MapGet("/", () => "Hello World!");

app.MapControllers();

app.Run();