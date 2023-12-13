### prompt start
# Write a PowerShell script to create a new directory with path and name specified by script parameters.
### prompt end
param(
    [string]$directoryPath,
    [string]$directoryName
)

$newDirectoryPath = Join-Path -Path $directoryPath -ChildPath $directoryName
New-Item -Path $newDirectoryPath -ItemType Directory