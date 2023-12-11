var builder = WebApplication.CreateBuilder(args);

 // Add authentication services
   builder.services.AddAuthentication(CookieAuthenticationDefaults.AuthenticationScheme)
       .AddCookie(options =>
       {
           options.LoginPath = "/Account/Login";
           options.AccessDeniedPath = "/Account/Forbidden";
       });

   // Add OpenID Connect authentication services
   builder.services.AddAuthentication(OpenIdConnectDefaults.AuthenticationScheme)
       .AddOpenIdConnect(options =>
       {
           options.Authority = "https://your-openid-connect-provider.com";
           options.ClientId = "your-client-id";
           options.ClientSecret = "your-client-secret";
           options.ResponseType = "code";
           options.Scope.Add("openid");
           options.Scope.Add("profile");
           options.Scope.Add("email");
           options.GetClaimsFromUserInfoEndpoint = true;
           options.UserInfoEndpointClaimsMapping.Add("sub", "sub");
           options.UserInfoEndpointClaimsMapping.Add("name", "name");
           options.UserInfoEndpointClaimsMapping.Add("given_name", "given_name");
           options.UserInfoEndpointClaimsMapping.Add("family_name", "family_name");
           options.UserInfoEndpointClaimsMapping.Add("email", "email");
       });

   // Add CSFR middleware
   builder.services.AddMvc(options =>
   {
       options.Filters.Add(typeof(CsrfFilter));
   });

var app = builder.Build();

// Add middleware for cookie-based authentication
app.UseAuthentication();

// Add middleware for CSFR protection
app.Use(async (context, next) =>
{
    if (context.Request.Path != "/favicon.ico")
    {
        var antiForgeryToken = context.Request.Query.GetValue<string>("__RequestVerificationToken");
        if (antiForgeryToken != null && !string.IsNullOrEmpty(antiForgeryToken))
        {
            context.Request.Headers["X-Requested-With"] = "XMLHttpRequest";
            context.Request.Headers["__RequestVerificationToken"] = antiForgeryToken;
        }
    }
    await next();
});

app.MapGet("/", () => "Hello World!");

app.MapControllers();

app.Run();