### prompt start
# Write a PowerShell script to delete a file only if it is a regular file.
### prompt end
# Define variables
$filePath = "C:\MyFile.txt"

# Check if file exists, if not, exit script
if (!(Test-Path -Path $filePath)) {
Write-Output "File not found: $($filePath)"
return
}

# Check if file is a regular file, if not, exit script
if (!(Get-Item -Path $filePath).IsFile()) {
Write-Output "Not a regular file: $($filePath)"
return
}

# Delete the file
Remove-Item -Path $filePath

# Verify file was deleted
Write-Output "File deleted: $($filePath)"