### prompt start
# Write a PowerShell script to find the largest files in a directory.
### prompt end
# Define variables
$directoryPath = "C:\MyDirectory"
$numberOfFiles = 5

# Check if directory exists, if not, exit script
if (!(Test-Path -Path $directoryPath)) {
 Write-Output "Directory not found: $($directoryPath)"
 return
}

# Get the file paths in the directory
$filePaths = Get-ChildItem -Path $directoryPath -Recurse | Select-Object -ExpandProperty FullName

# Create an array to store the file sizes
$fileSizes = @()

# Loop through the file paths and store the file sizes in the array
foreach ($filePath in $filePaths) {
 $fileSize = (Get-Item -Path $filePath).Length
 $fileSizes += New-Object PSObject -Property @{
   FilePath = $filePath
   FileSize = $fileSize
 }
}

# Sort the array by file size in descending order
$fileSizes = $fileSizes | Sort-Object -Property FileSize -Descending

# Output the largest files
Write-Output "Largest files in directory: $($directoryPath)"
Write-Output "--------------------------------------"
for ($i = 0; $i -lt $numberOfFiles; $i++) {
 Write-Output "$($fileSizes[$i].FileSize) bytes - $($fileSizes[$i].FilePath)"
}