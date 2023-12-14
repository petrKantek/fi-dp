### prompt start
# Write a PowerShell script to find and replace text in a file.
### prompt end
# Define variables
$filePath = "C:\MyFile.txt"
$searchText = "old_text"
$replaceText = "new_text"

# Check if file exists, if not, exit script
if (!(Test-Path -Path $filePath)) {
 Write-Output "File not found: $($filePath)"
 return
}

# Read the file contents
$fileContents = Get-Content -Path $filePath

# Replace the text
$newFileContents = $fileContents -replace $searchText, $replaceText

# Write the new contents to the file
Set-Content -Path $filePath -Value $newFileContents

# Verify the changes were made
Write-Output "Text replaced in file: $($filePath)"