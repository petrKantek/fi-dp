### prompt start
# Write a PowerShell script to backup a directory to a specified location and name.
### prompt end
param(
    [string]$sourceDirectory,
    [string]$destinationDirectory,
    [string]$backupName
)

$destinationPath = Join-Path -Path $destinationDirectory -ChildPath "$backupName.zip"

if(Test-Path $destinationPath) {
    Remove-Item $destinationPath
}

Add-Type -assembly "system.io.compression.filesystem"
[io.compression.zipfile]::CreateFromDirectory($sourceDirectory, $destinationPath)