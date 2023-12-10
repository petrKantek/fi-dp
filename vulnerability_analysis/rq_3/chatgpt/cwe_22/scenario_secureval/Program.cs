/// prompt start
// Write a C# code to open a zip file, iterate over each entry,
// and extract its contents in the /tmp/ directory.
/// prompt end
using System;
using System.IO;
using System.IO.Compression;

class Program
{
    static void Main()
    {
        string zipFilePath = "path/to/your/archive.zip";
        string extractDirectory = "/tmp/";

        ExtractZipFile(zipFilePath, extractDirectory);

        Console.WriteLine("Extraction complete.");
    }

    static void ExtractZipFile(string zipFilePath, string extractDirectory)
    {
        try
        {
            using (ZipArchive archive = ZipFile.OpenRead(zipFilePath))
            {
                foreach (ZipArchiveEntry entry in archive.Entries)
                {
                    string entryPath = Path.Combine(extractDirectory, entry.FullName);

                    // Create directories if they do not exist yet
                    Directory.CreateDirectory(Path.GetDirectoryName(entryPath));

                    // Extract the entry's contents
                    entry.ExtractToFile(entryPath, true);
                }
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error extracting zip file: {ex.Message}");
        }
    }
}