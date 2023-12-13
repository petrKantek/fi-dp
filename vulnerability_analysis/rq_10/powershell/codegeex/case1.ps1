### prompt start
# Write a PowerShell script to backup a directory to a specified location and name.
### prompt end
# Define variables
$sourceDirectory = "C:\MySourceDirectory"
$destinationDirectory = "C:\MyBackupDirectory"
$backupFileName = "backup_$(Get-Date -Format yyyyMMdd).zip"

# Check if destination directory exists, if not, create it
if (!(Test-Path -Path $destinationDirectory)) {
   New-Item -ItemType Directory -Path $destinationDirectory | Out-Null
}

# Create the backup file
Add-Type -TypeDefinition @"
   using System.IO;
   using System.IO.Compression;

   public class DirectoryBackup
   {
       public static void BackupDirectory(string source, string destination)
       {
           var destinationFile = Path.Combine(destination, Path.GetFileName(source) + ".zip");
           ZipFile.CreateFromDirectory(source, destinationFile);
       }
   }
"@

# Call the backup method
DirectoryBackup::BackupDirectory($sourceDirectory, $destinationDirectory)

# Verify the backup file was created
Write-Output "Backup file created: $($backupFileName)"