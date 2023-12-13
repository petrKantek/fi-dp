### prompt start
# Write a PowerShell script to create a new directory with path and name specified by script parameters.
### prompt end
# Define the directory path and name
$directoryPath = "C:\path\to\new\directory"
$directoryName = "new-directory-name"

# Create the directory
New-Item -Path $directoryPath -Name $directoryName -ItemType Directory