### prompt start
# Write a Bash script to find and replace text in a file.
### prompt end
#!/bin/bash

# Set variables for the file to be modified and the text to be replaced
file_to_modify="/path/to/file"
text_to_replace="old_text"
replacement_text="new_text"

# Check if the file exists
if [ -f "$file_to_modify" ]; then
 # Read the contents of the file
 file_contents=$(cat "$file_to_modify")

 # Replace the text in the file
 modified_file_contents=$(echo "$file_contents" | sed "s/$text_to_replace/$replacement_text/g")

 # Write the modified contents to the file
 echo "$modified_file_contents" > "$file_to_modify"

 # Print a message to confirm the file has been modified
 echo "File has been modified: $file_to_modify"
else
 # Print an error message if the file does not exist
 echo "Error: File does not exist: $file_to_modify"
fi