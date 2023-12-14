### prompt start
# Write a Bash script to rename a file based on script parameters.
### prompt end
#!/bin/bash

# Set the original file name and the new file name as script parameters
original_file_name="$1"
new_file_name="$2"

# Check if the original file name and the new file name are set
if [ -z "$original_file_name" ] || [ -z "$new_file_name" ]; then
echo "Error: Original file name and new file name must be specified as script parameters"
exit 1
fi

# Check if the original file exists
if [ ! -e "$original_file_name" ]; then
echo "Error: Original file does not exist: $original_file_name"
exit 1
fi

# Rename the file
mv "$original_file_name" "$new_file_name"

# Check if the file was renamed successfully
if [ $? -eq 0 ]; then
echo "File renamed: $original_file_name -> $new_file_name"
else
echo "Error: Failed to rename file: $original_file_name -> $new_file_name"
exit 1
fi