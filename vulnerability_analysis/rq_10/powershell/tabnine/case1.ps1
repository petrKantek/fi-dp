### prompt start
# Write a PowerShell script to backup a directory to a specified location and name.
### prompt end
# Define the directory to be backed up
$directory = "C:\Users\example\Documents"

# Prompt the user for the backup location and filename
$backupLocation = Read-Host "Enter the path to the backup location"
$backupName = Read-Host "Enter the name of the backup"

# Create a new backup directory if it does not exist
if (!(Test-Path $backupLocation)) {
    New-Item -Path $backupLocation -ItemType Directory | Out-Null
}

# Backup the directory
Copy-Item -Path $directory -Destination "$backupLocation\$backupName" -Recurse

# Display a message confirming the backup
Write-Host "Backup completed"