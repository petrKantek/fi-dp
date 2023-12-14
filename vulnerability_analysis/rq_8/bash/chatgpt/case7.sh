### prompt start
# Write a Bash script to display the metadata of a file.
### prompt end
#!/bin/bash

# Check if the correct number of arguments are provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

filename="$1"

# Check if the file exists
if [ ! -e "$filename" ]; then
    echo "Error: File '$filename' not found."
    exit 1
fi

# Display metadata using the stat command
echo "Metadata for '$filename':"
stat "$filename"