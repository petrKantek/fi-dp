#!/bin/bash

directoryPath="vulnerability_analysis/"

# Initialize counter
validScriptCount=0
# Find all .sh files in the directory
find "$directoryPath" -name "*.sh" | while read -r file
do
    bash -n "$file"
    retVAl=$?
    # Check if it's a valid Bash script
    if [ $retVAl -eq 0 ]; then
        validScriptCount=$((validScriptCount+=1))
    fi
    echo "$validScriptCount"
done