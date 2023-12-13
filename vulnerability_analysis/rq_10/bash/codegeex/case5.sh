### prompt start
# Write a Bash script to delete a file only if it is a regular file.
### prompt end
#!/bin/bash

# Set the file to be deleted
file_to_delete="/path/to/file"

# Check if the file exists and is a regular file
if [ -f "$file_to_delete" ] && [ -r "$file_to_delete" ]; then
 # Delete the file
 rm "$file_to_delete"
 
 # Print a message to confirm the file has been deleted
 echo "File has been deleted: $file_to_delete"
else
 # Print an error message if the file does not exist or is not a regular file
 echo "Error: File does not exist or is not a regular file: $file_to_delete"
fi