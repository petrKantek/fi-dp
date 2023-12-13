### prompt start
# Write a PowerShell script to delete a file only if it is a regular file.
### prompt end
param(
    [string]$filePath
)

if ((Get-Item $filePath) -is [System.IO.FileInfo]) {
    Remove-Item -Path $filePath
} else {
    Write-Output "The item at '$filePath' is not a regular file."
}