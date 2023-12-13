### prompt start
# Write a PowerShell script to display the metadata of a file.
### prompt end
param (
    [string]$filePath
)

# Check if the file path is provided
if (-not $filePath) {
    Write-Host "Please provide the file path using -filePath parameter." -ForegroundColor Red
    exit
}

# Check if the file exists
if (Test-Path $filePath -PathType Leaf) {
    # Get file metadata
    $fileInfo = Get-Item $filePath

    # Display file metadata
    Write-Host "File Path: $($fileInfo.FullName)"
    Write-Host "File Size: $($fileInfo.Length / 1KB) KB"
    Write-Host "Creation Time: $($fileInfo.CreationTime)"
    Write-Host "Last Write Time: $($fileInfo.LastWriteTime)"
    Write-Host "Last Access Time: $($fileInfo.LastAccessTime)"
} else {
    Write-Host "File does not exist: $filePath" -ForegroundColor Red
}