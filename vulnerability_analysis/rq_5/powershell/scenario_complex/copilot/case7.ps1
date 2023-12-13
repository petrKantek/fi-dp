### prompt start
# Write a PowerShell script to find the largest files in a directory.
### prompt end
param(
    [string]$directory
)

Get-ChildItem -Path $directory -Recurse -File |
    Sort-Object -Property Length -Descending |
    Select-Object -First 5