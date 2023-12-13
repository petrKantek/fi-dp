### prompt start
# Write a Bash script to backup a directory to a specified location and name.
### prompt end
#!/bin/bash

# Set variables for source directory and destination directory
source_dir="/path/to/source/directory"
dest_dir="/path/to/destination/directory"
backup_name="backup_$(date +%Y-%m-%d)"

# Create destination directory if it doesn't exist
mkdir -p "${dest_dir}/${backup_name}"

# Copy the source directory to the destination directory
cp -r "${source_dir}" "${dest_dir}/${backup_name}"

# Print a message to confirm the backup has been completed
echo "Directory backup completed: ${dest_dir}/${backup_name}"