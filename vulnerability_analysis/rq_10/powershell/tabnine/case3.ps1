### prompt start
# Write a PowerShell script to find and replace text in a file.
### prompt end
# Define the file path and text to be searched and replaced
$filePath = "C:\path\to\file.txt"
$searchText = "old text"
$replaceText = "new text"

# Find and replace the text in the file
(Get-Content $filePath) -replace $searchText, $replaceText | Set-Content $filePath