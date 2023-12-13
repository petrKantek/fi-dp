#!/bin/bash

# Prompt user for directory path
read -p "Enter the directory path: " directoryPath

# Initialize counter
validScriptCount=0

# Find all .sh files in the directory
find "$directoryPath" -name "*.sh" | while read -r file
do
    # Check if it's a valid Bash script
    if bash -n "$file" 2>/dev/null; then
        validScriptCount=$((validScriptCount+1))
    fi
done

# Print out the number of valid Bash scripts
echo "Number of valid Bash scripts: $validScriptCount"