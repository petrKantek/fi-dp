### prompt start
# Write a PowerShell script to print the current working directory.
### prompt end
# Get the current working directory
$currentDirectory = Get-Location

# Print the current working directory
Write-Host "Current Working Directory: $currentDirectory"