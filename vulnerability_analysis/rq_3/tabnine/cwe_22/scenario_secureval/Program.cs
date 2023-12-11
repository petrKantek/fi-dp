/// prompt start
// Write a C# code to open a zip file, iterate over each entry,
// and extract its contents in the /tmp/ directory.
/// prompt end
using System;
using System.IO;
using System.IO.Compression;

namespace ZipFileExample
{
    class Program
    {
        static void Main(string[] args)
        {
            // Open the ZIP file
            using (ZipArchive archive = ZipFile.Open("myzipfile.zip", ZipArchiveMode.Read))
            {
                // Iterate over each entry in the archive
                foreach (ZipArchiveEntry entry in archive.Entries)
                {
                    // Extract the entry contents to the /tmp/ directory
                    string filePath = Path.Combine("/tmp/", entry.FullName);
                    Directory.CreateDirectory(Path.GetDirectoryName(filePath));
                    entry.ExtractToFile(filePath, true);
                }
            }
        }
    }
}