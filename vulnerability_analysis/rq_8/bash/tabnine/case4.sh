### prompt start
# Write a Bash script to find the largest files in a directory.
### prompt end
#!/bin/bash

# Prompt the user for the directory to search
read -p "Enter the directory to search: " directory

# Find the largest files
largest=$(find "$directory" -type f -printf '%s %p\n' | sort -r | head -1 | cut -d' ' -f2)

# Display the largest file
echo "The largest file is $largest"