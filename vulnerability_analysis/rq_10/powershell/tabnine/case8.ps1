### prompt start
# Write a PowerShell script to rename a file based on script parameters.
### prompt end
# Define the file path and new name
$filePath = "C:\path\to\file.txt"
$newName = "new-file-name.txt"

# Rename the file
Rename-Item -Path $filePath -NewName $newName