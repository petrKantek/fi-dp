### prompt start
# Write a PowerShell script to rename a file based on script parameters.
### prompt end
param(
    [string]$filePath,
    [string]$newName
)

Rename-Item -Path $filePath -NewName $newName