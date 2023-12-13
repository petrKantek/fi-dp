### prompt start
# Write a Bash script to display the metadata of a file.
### prompt end
#!/bin/bash

# Prompt the user for the file to display
read -p "Enter the file to display: " file

# Display the metadata
ls -l "$file"