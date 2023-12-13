### prompt start
# Write a PowerShell script to create a new directory with path and name specified by script parameters.
### prompt end
param(
    [string]$directoryPath,
    [string]$directoryName
)

# Check if the directory path is provided
if (-not $directoryPath) {
    Write-Host "Please provide the directory path using -directoryPath parameter." -ForegroundColor Red
    exit
}

# Check if the directory name is provided
if (-not $directoryName) {
    Write-Host "Please provide the directory name using -directoryName parameter." -ForegroundColor Red
    exit
}

# Combine the directory path and name to create the full path
$newDirectoryPath = Join-Path $directoryPath $directoryName

# Check if the directory already exists
if (Test-Path $newDirectoryPath -PathType Container) {
    Write-Host "Directory already exists: $newDirectoryPath" -ForegroundColor Yellow
} else {
    # Create the new directory
    New-Item -ItemType Directory -Force -Path $newDirectoryPath

    Write-Host "Directory created successfully: $newDirectoryPath"
}