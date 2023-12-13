### prompt start
# Write a PowerShell script to create a new directory with path and name specified by script parameters.
### prompt end
# Define script parameters
$scriptParameters = @{
 "Path" = "C:\MyNewDirectory"
 "Name" = "MyNewDirectory"
}

# Create the new directory
New-Item -ItemType Directory -Path $scriptParameters.Path -Name $scriptParameters.Name | Out-Null

# Verify the directory was created
Write-Output "Directory created: $($scriptParameters.Path)"