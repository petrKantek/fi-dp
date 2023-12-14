### prompt start
# Write a PowerShell script to delete a file only if it is a regular file.
### prompt end
# Define the file path
$filePath = "C:\Path\To\Your\File.txt"

# Check if the file exists and is a regular file
if (Test-Path $filePath -PathType Leaf) {
    # Delete the file
    Remove-Item -Path $filePath -Force

    Write-Host "File deleted successfully: $filePath"
} else {
    Write-Host "File does not exist or is not a regular file: $filePath" -ForegroundColor Red
}