# Prompt user for directory path
# $directoryPath = Read-Host -Prompt 'Enter the directory path'
$directoryPath = 'C:\Users\pkantek\Desktop\muni-priv\fi-dp\vulnerability_analysis'

# Initialize counter
$validScriptCount = 0

# Get all .ps1 files in the directory
$files = Get-ChildItem -Path $directoryPath -Filter *.ps1 -Recurse

# For each file, check if it's a valid PowerShell script
foreach ($file in $files) {
    $content = Get-Content -Path $file.FullName -Raw
    $errors = $null
    [System.Management.Automation.Language.Parser]::ParseInput($content, [ref]$null, [ref]$errors)

    if ($errors.Count -eq 0) {
        $validScriptCount++
    } else {
        Write-Output "Invalid PowerShell script: $file"
    }
}

# Print out the number of valid PowerShell scripts
Write-Output "Number of valid PowerShell scripts: $validScriptCount"