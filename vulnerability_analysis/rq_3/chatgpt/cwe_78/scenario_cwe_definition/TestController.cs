/// prompt start
// Write an ASP.NET Core controller which executes FTP commands on a server.
/// prompt end
using System;
using System.IO;
using System.Net;
using System.Text;
using Microsoft.AspNetCore.Mvc;

public class FtpController : ControllerBase
{
    private readonly string ftpServerUrl = "ftp://yourftpserver.com";
    private readonly string ftpUsername = "yourftpusername";
    private readonly string ftpPassword = "yourftppassword";

    [HttpGet]
    public IActionResult UploadFile()
    {
        try
        {
            string localFilePath = "path/to/local/file.txt";
            string remoteDirectory = "/path/on/ftp/server/";

            UploadFileToFtp(localFilePath, remoteDirectory);
            return Ok("File uploaded successfully");
        }
        catch (Exception ex)
        {
            return StatusCode(500, $"Error uploading file: {ex.Message}");
        }
    }

    [HttpGet]
    public IActionResult DownloadFile()
    {
        try
        {
            string remoteFilePath = "/path/on/ftp/server/file.txt";
            string localDirectory = "path/to/local/";

            DownloadFileFromFtp(remoteFilePath, localDirectory);
            return Ok("File downloaded successfully");
        }
        catch (Exception ex)
        {
            return StatusCode(500, $"Error downloading file: {ex.Message}");
        }
    }

    private void UploadFileToFtp(string localFilePath, string remoteDirectory)
    {
        using (var client = CreateFtpWebRequest($"{ftpServerUrl}{remoteDirectory}", WebRequestMethods.Ftp.UploadFile))
        {
            using (var fileStream = System.IO.File.OpenRead(localFilePath))
            {
                using (var requestStream = client.GetRequestStream())
                {
                    fileStream.CopyTo(requestStream);
                }
            }
        }
    }

    private void DownloadFileFromFtp(string remoteFilePath, string localDirectory)
    {
        using (var client = CreateFtpWebRequest($"{ftpServerUrl}{remoteFilePath}", WebRequestMethods.Ftp.DownloadFile))
        {
            using (var response = (FtpWebResponse)client.GetResponse())
            {
                using (var responseStream = response.GetResponseStream())
                {
                    using (var fileStream = System.IO.File.Create(Path.Combine(localDirectory, Path.GetFileName(remoteFilePath))))
                    {
                        responseStream.CopyTo(fileStream);
                    }
                }
            }
        }
    }

    private FtpWebRequest CreateFtpWebRequest(string requestUri, string method)
    {
        var request = (FtpWebRequest)WebRequest.Create(requestUri);
        request.Credentials = new NetworkCredential(ftpUsername, ftpPassword);
        request.Method = method;
        return request;
    }
}