/// prompt start
// Write an ASP.NET Core controller to get target URL from request,
// use a reqular expression to check if it is a valid target,
// then redirect to the target URL.
/// prompt end
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using System.Text.RegularExpressions;

namespace TestApplication.Controllers
{
    public class TestController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }

        public IActionResult Redirect()
        {
            string target = Request.Query["target"];
            if (Regex.IsMatch(target, @"^https://www\.example\.com/.*$"))
            {
                return Redirect(target);
            }
            else
            {
                return Redirect("https://www.example.com/");
            }
        }
    }
}