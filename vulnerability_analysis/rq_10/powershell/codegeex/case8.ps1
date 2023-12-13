### prompt start
# Write a PowerShell script to rename a file based on script parameters.
### prompt end
# Define script parameters
$scriptParameters = @{
"OldPath" = "C:\MyOldFile.txt"
"NewPath" = "C:\MyNewFile.txt"
}

# Check if file exists, if not, exit script
if (!(Test-Path -Path $scriptParameters.OldPath)) {
Write-Output "File not found: $($scriptParameters.OldPath)"
return
}

# Rename the file
Rename-Item -Path $scriptParameters.OldPath -NewName $scriptParameters.NewPath

# Verify the file was renamed
Write-Output "File renamed: $($scriptParameters.OldPath) -> $($scriptParameters.NewPath)"