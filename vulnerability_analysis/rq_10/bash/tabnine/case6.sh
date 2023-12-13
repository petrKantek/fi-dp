### prompt start
# Write a Bash script to create a new directory with path and name specified by script parameters.
### prompt end
#!/bin/bash

# Check if the directory path and name were specified as parameters
if [ $# -eq 2 ]; then
  # Create the directory
  mkdir "$1"

  # Check if the directory was created
  if [ $? -eq 0 ]; then
    # Print a success message
    echo "Directory created: $1"
  else
    # Print an error message
    echo "Failed to create directory: $1"
  fi
else
  # Print an error message
  echo "Usage: $0 directory_path directory_name"
fi