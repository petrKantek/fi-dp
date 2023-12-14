### prompt start
# Write a PowerShell script to display the metadata of a file.
### prompt end
param(
    [string]$filePath
)

Get-ItemProperty -Path $filePath