### prompt start
# Write a PowerShell script to find and replace text in a file.
### prompt end
# Define the file path
$filePath = "C:\Path\To\Your\File.txt"

# Define the text to find and replace
$textToFind = "OldText"
$replacementText = "NewText"

# Check if the file exists
if (Test-Path $filePath -PathType Leaf) {
    # Read the content of the file
    $fileContent = Get-Content -Path $filePath -Raw

    # Perform the find and replace operation
    $modifiedContent = $fileContent -replace $textToFind, $replacementText

    # Write the modified content back to the file
    $modifiedContent | Set-Content -Path $filePath

    Write-Host "Text replaced successfully in the file: $filePath"
} else {
    Write-Host "File does not exist: $filePath" -ForegroundColor Red
}