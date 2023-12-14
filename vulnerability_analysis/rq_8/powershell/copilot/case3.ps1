### prompt start
# Write a PowerShell script to find and replace text in a file.
### prompt end
param(
    [string]$filePath,
    [string]$findText,
    [string]$replaceText
)

(Get-Content $filePath) | ForEach-Object {
    $_ -replace $findText, $replaceText
} | Set-Content $filePath