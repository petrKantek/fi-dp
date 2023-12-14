### prompt start
# Write a Bash script to rename a file based on script parameters.
### prompt end
#!/bin/bash

# Check if the correct number of arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <old_filename> <new_filename>"
    exit 1
fi

old_filename="$1"
new_filename="$2"

# Check if the file exists
if [ ! -e "$old_filename" ]; then
    echo "Error: File '$old_filename' not found."
    exit 1
fi

# Rename the file
mv "$old_filename" "$new_filename"

echo "File '$old_filename' renamed to '$new_filename' successfully."