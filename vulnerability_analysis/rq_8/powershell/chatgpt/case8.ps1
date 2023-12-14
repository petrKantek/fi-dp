### prompt start
# Write a PowerShell script to rename a file based on script parameters.
### prompt end
param (
    [string]$filePath,
    [string]$newFileName
)

# Check if the file path is provided
if (-not $filePath) {
    Write-Host "Please provide the file path using -filePath parameter." -ForegroundColor Red
    exit
}

# Check if the new file name is provided
if (-not $newFileName) {
    Write-Host "Please provide the new file name using -newFileName parameter." -ForegroundColor Red
    exit
}

# Check if the file exists
if (Test-Path $filePath -PathType Leaf) {
    # Get the directory path of the file
    $fileDirectory = (Get-Item $filePath).Directory.FullName

    # Construct the new file path
    $newFilePath = Join-Path $fileDirectory $newFileName

    # Rename the file
    Rename-Item -Path $filePath -NewName $newFileName -Force

    Write-Host "File renamed successfully. New file path: $newFilePath"
} else {
    Write-Host "File does not exist: $filePath" -ForegroundColor Red
}