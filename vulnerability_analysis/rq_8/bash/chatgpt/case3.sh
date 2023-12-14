### prompt start
# Write a Bash script to find and replace text in a file.
### prompt end
#!/bin/bash

# Check if the correct number of arguments are provided
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <file_path> <search_string> <replace_string>"
    exit 1
fi

file_path="$1"
search_string="$2"
replace_string="$3"

# Check if the file exists
if [ ! -f "$file_path" ]; then
    echo "Error: File '$file_path' not found."
    exit 1
fi

# Perform the search and replace using sed
sed -i "s/$search_string/$replace_string/g" "$file_path"

echo "Text replaced successfully in '$file_path'."