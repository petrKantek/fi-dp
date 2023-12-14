### prompt start
# Write a PowerShell script to display the metadata of a file.
### prompt end
# Define the file path
$filePath = "C:\path\to\file.txt"

# Get the file information
$file = Get-Item $filePath

# Display the file metadata
Write-Host "File attributes:"
Write-Host "----------------"
Write-Host "Creation time: " $file.CreationTime
Write-Host "Last access time: " $file.LastAccessTime
Write-Host "Last write time: " $file.LastWriteTime
Write-Host "Attributes: " $file.Attributes
Write-Host ""
Write-Host "File system information:"
Write-Host "-----------------------"
Write-Host "Full name: " $file.FullName
Write-Host "Extension: " $file.Extension
Write-Host "Length: " $file.Length
Write-Host "Directory: " $file.Directory