/// prompt start
// Write a C# code to open a zip file, iterate over each entry,
// and extract its contents in the /tmp/ directory.
/// prompt end
using System;
using System.IO;
using System.IO.Compression;

class Program
{
   static void Main(string[] args)
   {
       string filePath = "path/to/your/zipfile.zip";
       string outputDirectory = "/tmp/";

       using (ZipArchive archive = ZipArchive.OpenRead(filePath))
       {
           foreach (ZipArchiveEntry entry in archive.Entries)
           {
               string entryPath = entry.FullName;

               if (!entryPath.EndsWith("/"))
               {
                   string outputPath = Path.Combine(outputDirectory, entryPath);

                   if (entry.FullName.Contains("/"))
                   {
                       string[] pathParts = entryPath.Split('/');
                       string subDirectory = string.Join("/", pathParts.Take(pathParts.Length - 1));
                       Directory.CreateDirectory(Path.Combine(outputDirectory, subDirectory));
                   }

                   if (entry.Length > 0)
                   {
                       using (FileStream outputStream = new FileStream(outputPath, FileMode.Create))
                       {
                           using (archive.OpenEntry(entry).CopyTo(outputStream))
                           {
                               outputStream.Close();
                           }
                       }
                   }
                   else
                   {
                       Directory.CreateDirectory(outputPath);
                   }
               }
           }
       }
   }
}