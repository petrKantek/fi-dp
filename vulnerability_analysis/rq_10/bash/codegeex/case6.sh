### prompt start
# Write a Bash script to create a new directory with path and name specified by script parameters.
### prompt end
#!/bin/bash

# Set the directory path and name from script parameters
dir_path="$1"
dir_name="$2"

# Check if the directory path and name are set
if [ -z "$dir_path" ] || [ -z "$dir_name" ]; then
 echo "Error: Directory path and name must be specified as script parameters"
 exit 1
fi

# Create the directory
mkdir -p "$dir_path"/"$dir_name"

# Check if the directory was created successfully
if [ $? -eq 0 ]; then
 echo "Directory created: $dir_path/$dir_name"
else
 echo "Error: Failed to create directory: $dir_path/$dir_name"
 exit 1
fi
