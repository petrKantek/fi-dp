### prompt start
# Write a PowerShell script to display the metadata of a file.
### prompt end
# Define variables
$filePath = "C:\MyFile.txt"

# Check if file exists, if not, exit script
if (!(Test-Path -Path $filePath)) {
Write-Output "File not found: $($filePath)"
return
}

# Get the file metadata
$fileMetadata = Get-Item -Path $filePath

# Display the file metadata
Write-Output "File metadata for $($fileMetadata.Name):"
Write-Output "--------------------------------------"
Write-Output "Created: $($fileMetadata.CreationTime)"
Write-Output "Modified: $($fileMetadata.LastWriteTime)"
Write-Output "Attributes: $($fileMetadata.Attributes)"
Write-Output "Length: $($fileMetadata.Length) bytes"