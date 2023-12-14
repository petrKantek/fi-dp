### prompt start
# Write a PowerShell script to find the largest files in a directory.
### prompt end
# Define the directory path
$directoryPath = "C:\Path\To\Your\Directory"

# Define the number of top files to display
$topFilesCount = 5

# Check if the directory exists
if (Test-Path $directoryPath -PathType Container) {
    # Get the files in the directory and sort them by size in descending order
    $largestFiles = Get-ChildItem -Path $directoryPath -File | Sort-Object Length -Descending | Select-Object -First $topFilesCount

    # Display information about the largest files
    foreach ($file in $largestFiles) {
        Write-Host "File: $($file.FullName)"
        Write-Host "Size: $($file.Length / 1MB) MB"
        Write-Host "Last Modified: $($file.LastWriteTime)"
        Write-Host "-----------------------------"
    }
} else {
    Write-Host "Directory does not exist: $directoryPath" -ForegroundColor Red
}