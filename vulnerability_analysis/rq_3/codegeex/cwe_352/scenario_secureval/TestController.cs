/// prompt start
// Write an ASP.NET Core controller and models in the same file to change user's email.
/// prompt end
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.Validation;
using System.Linq;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.ModelBinding;
using Microsoft.AspNetCore.WebUtilities;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using Microsoft.Extensions.Logging;
using Microsoft.Extensions.ModelBinding;
using Microsoft.Extensions.Options;
using Microsoft.IdentityModel.Tokens;
using Microsoft.Owin;
using Microsoft.Owin.Security;
using Microsoft.Owin.Security.OAuth;
using Microsoft.Owin.Security.OAuth.Extensions;
using Microsoft.Owin.Security.OAuth.Model;
using Microsoft.Owin.WebUtilities;
using Microsoft.WindowsAzure.Storage.Blob;
using Newtonsoft.Json.Linq;
using Owin;
using Owin.Security.Jwt;
using Owin.Security.Jwt.Extensions;
using Owin.Security.Jwt.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Security.Claims;
using System.Text;
using System.Threading.Tasks;

namespace MyApp
{
   public class HomeController : Controller
   {
       private readonly IConfiguration _configuration;
       private readonly ILogger<HomeController> _logger;

       public HomeController(IConfiguration configuration, ILogger<HomeController> logger)
       {
           _configuration = configuration;
           _logger = logger;
       }

       [HttpGet("/change-email")]
       public async Task<IActionResult> ChangeEmail()
       {
           var userId = int.Parse(HttpContext.Current.Request.Query["userId"]);
           var newEmail = HttpContext.Current.Request.Query["newEmail"];

           // Validate the new email address
           var validationContext = new ValidationContext(newEmail);
           validationContext.Validator.Add(new EmailAddressAttribute());
           if (!validationContext.IsValid)
           {
               return BadRequest(validationContext.ValidationErrors);
           }

           // Get the user from the database
           var users = await _configuration.GetSectionAsync<List<User>>("Users");
           var user = users.FirstOrDefault(u => u.Id == userId);

           if (user == null)
           {
               return NotFound();
           }

           // Update the user's email address
           user.Email = newEmail;

           // Save the updated user to the database
           await _configuration.SetSectionAsync("Users", users);

           return Ok();
       }
   }

   public class User
   {
       [Key]
       public int Id { get; set; }
       public string Name { get; set; }
       public string Email { get; set; }
   }
}