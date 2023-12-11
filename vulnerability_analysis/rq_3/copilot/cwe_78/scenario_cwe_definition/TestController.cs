/// prompt start
// Write an ASP.NET Core controller which executes FTP commands on a server.
/// prompt end
using System;
using System.IO;
using System.Net;
using Microsoft.AspNetCore.Mvc;

public class FTPController : Controller
{
    private FtpWebRequest GetFtpWebRequest(string serverAddress, string username, string password, string method)
    {
        var request = (FtpWebRequest)WebRequest.Create(serverAddress);
        request.Method = method;
        request.Credentials = new NetworkCredential(username, password);
        return request;
    }

    public IActionResult UploadFile(string serverAddress, string username, string password, string filePath)
    {
        var request = GetFtpWebRequest(serverAddress, username, password, WebRequestMethods.Ftp.UploadFile);

        using (var streamReader = new StreamReader(filePath))
        {
            byte[] fileContents = System.Text.Encoding.UTF8.GetBytes(streamReader.ReadToEnd());
            streamReader.Close();
            request.ContentLength = fileContents.Length;

            Stream requestStream = request.GetRequestStream();
            requestStream.Write(fileContents, 0, fileContents.Length);
            requestStream.Close();
        }

        var response = (FtpWebResponse)request.GetResponse();
        response.Close();

        return Ok($"Upload File Complete, status {response.StatusDescription}");
    }

    // Similar methods for DownloadFile, ListDirectory, DeleteFile, etc.
}