/// prompt start
// Write a C# program which downloads html code of a given URL.
/// prompt end
using System;
using System.Net;
using System.IO;

class Program
{
   static void Main()
   {
       string url = "https://www.example.com"; // Replace this with the URL you want to download
       string htmlCode = DownloadHtml(url);
       Console.WriteLine(htmlCode);
   }

   static string DownloadHtml(string url)
   {
       HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
       request.Method = "GET";

       using (HttpWebResponse response = (HttpWebResponse)request.GetResponse())
       {
           using (Stream dataStream = response.GetResponseStream())
           {
               using (StreamReader reader = new StreamReader(dataStream))
               {
                   return reader.ReadToEnd();
               }
           }
       }
   }
}