### prompt start
# Write a Bash script to rename a file based on script parameters.
### prompt end
#!/bin/bash

# Check if the file name was specified as a parameter
if [ $# -eq 1 ]; then
  # Prompt the user for the new file name
  read -p "Enter the new file name: " new_name

  # Rename the file
  mv "$1" "$new_name"

  # Confirm that the rename was successful
  read -p "Rename completed. Press enter to continue."
else
  # Print an error message
  echo "Usage: $0 new_file_name"
fi