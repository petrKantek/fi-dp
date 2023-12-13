### prompt start
# Write a Bash script to find and replace text in a file.
### prompt end
#!/bin/bash

# Prompt the user for the file to edit and the text to find and replace
read -p "Enter the file to edit: " file
read -p "Enter the text to find: " find
read -p "Enter the text to replace it with: " replace

# Replace the text in the file
sed -i "s/$find/$replace/g" "$file"

# Confirm that the replacement was successful
read -p "Replacement completed. Press enter to continue."