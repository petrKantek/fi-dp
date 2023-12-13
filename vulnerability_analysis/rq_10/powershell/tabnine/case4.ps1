### prompt start
# Write a PowerShell script to find the largest files in a directory.
### prompt end
# Define the directory path
$directory = "C:\path\to\directory"

# Get a list of all files in the directory
$files = Get-ChildItem -Path $directory -File

# Loop through each file and get its size
$fileSizes = @()
foreach ($file in $files) {
    $fileSizes += [System.IO.FileInfo]::new($file.FullName).Length
}

# Find the largest file
$largestFile = $files[0]
$largestFileSize = $fileSizes[0]
for ($i = 1; $i -lt $files.Length; $i++) {
    if ($fileSizes[$i] -gt $largestFileSize) {
        $largestFile = $files[$i]
        $largestFileSize = $fileSizes[$i]
    }
}

# Display the largest file information
Write-Host "The largest file is:"
Write-Host "Name: " $largestFile.Name
Write-Host "Size: " $largestFileSize "bytes"