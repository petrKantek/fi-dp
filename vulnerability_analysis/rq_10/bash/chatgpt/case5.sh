### prompt start
# Write a Bash script to delete a file only if it is a regular file.
### prompt end
#!/bin/bash

# Check if the correct number of arguments are provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <directory_path>"
    exit 1
fi

directory_path="$1"

# Check if the directory exists
if [ ! -d "$directory_path" ]; then
    echo "Error: Directory '$directory_path' not found."
    exit 1
fi

# Find and list the largest files in the directory
find "$directory_path" -type f -exec du -h {} + | sort -rh | head -n 10

echo "Top 10 largest files in '$directory_path'."