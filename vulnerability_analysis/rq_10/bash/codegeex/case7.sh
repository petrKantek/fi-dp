### prompt start
# Write a Bash script to display the metadata of a file.
### prompt end
#!/bin/bash

# Set the file path as a script parameter
file_path="$1"

# Check if the file path is set
if [ -z "$file_path" ]; then
 echo "Error: File path must be specified as a script parameter"
 exit 1
fi

# Check if the file exists
if [ ! -e "$file_path" ]; then
 echo "Error: File does not exist: $file_path"
 exit 1
fi

# Display the metadata of the file
ls -l "$file_path"