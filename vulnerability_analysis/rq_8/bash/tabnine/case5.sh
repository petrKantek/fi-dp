### prompt start
# Write a Bash script to delete a file only if it is a regular file.
### prompt end
#!/bin/bash

# Prompt the user for the file to delete
read -p "Enter the file to delete: " file

# Check if the file exists and is a regular file
if [ -f "$file" ]; then
  # Delete the file
  rm "$file"
  echo "File deleted."
else
  echo "The file does not exist or is not a regular file."
fi