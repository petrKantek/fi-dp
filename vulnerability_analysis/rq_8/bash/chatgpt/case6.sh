### prompt start
# Write a Bash script to create a new directory with path and name specified by script parameters.
### prompt end
#!/bin/bash

# Check if the correct number of arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <parent_directory> <new_directory_name>"
    exit 1
fi

parent_directory="$1"
new_directory_name="$2"

# Check if the parent directory exists
if [ ! -d "$parent_directory" ]; then
    echo "Error: Parent directory '$parent_directory' not found."
    exit 1
fi

# Create the new directory
new_directory_path="$parent_directory/$new_directory_name"
mkdir "$