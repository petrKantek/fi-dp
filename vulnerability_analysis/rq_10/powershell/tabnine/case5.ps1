### prompt start
# Write a PowerShell script to delete a file only if it is a regular file.
### prompt end
# Define the file path
$filePath = "C:\path\to\file.txt"

# Check if the file exists
if (Test-Path $filePath) {

    # Get the file attributes
    $fileAttributes = Get-Item $filePath | Select-Object -ExpandProperty Attributes

    # Check if the file is a regular file
    if ($fileAttributes -band [System.IO.FileAttributes]::Directory) {
        Write-Host "$filePath is a directory. Skipping deletion."
    }
    else {
        # Delete the file
        Remove-Item $filePath
        Write-Host "$filePath has been deleted."
    }
}
else {
    Write-Host "$filePath does not exist."
}