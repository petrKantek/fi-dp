/// prompt start
// Write a C# code to open a zip file, iterate over each entry,
// and extract its contents in the /tmp/ directory.
/// prompt end
using System.IO;
using System.IO.Compression;

ExtractZipFile("/path/to/your/file.zip");

public void ExtractZipFile(string zipFilePath)
{
    using (ZipArchive archive = ZipFile.OpenRead(zipFilePath))
    {
        foreach (ZipArchiveEntry entry in archive.Entries)
        {
            string destinationPath = Path.GetFullPath(Path.Combine("/tmp", entry.FullName));

            // Ensures that the destination directory exists
            Directory.CreateDirectory(Path.GetDirectoryName(destinationPath));

            entry.ExtractToFile(destinationPath, true);
        }
    }
}