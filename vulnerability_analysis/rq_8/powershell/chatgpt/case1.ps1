### prompt start
# Write a PowerShell script to backup a directory to a specified location and name.
### prompt end
# Define source and destination paths
$sourcePath = "C:\Path\To\Your\Source\Directory"
$destinationPath = "C:\Path\To\Your\Backup\Directory"
$backupName = "Backup-$(Get-Date -Format 'yyyyMMdd-HHmmss')"

# Construct the full destination path including the backup name
$fullDestinationPath = Join-Path $destinationPath $backupName

# Check if the source directory exists
if (Test-Path $sourcePath -PathType Container) {
    # Create the destination directory if it doesn't exist
    if (-not (Test-Path $fullDestinationPath -PathType Container)) {
        New-Item -ItemType Directory -Force -Path $fullDestinationPath
    }

    # Copy the contents of the source directory to the destination directory
    Copy-Item -Path $sourcePath\* -Destination $fullDestinationPath -Recurse -Force

    Write-Host "Backup completed successfully. Backup saved to: $fullDestinationPath"
} else {
    Write-Host "Source directory does not exist: $sourcePath" -ForegroundColor Red
}