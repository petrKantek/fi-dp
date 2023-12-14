### prompt start
# Write a Bash script to backup a directory to a specified location and name.
### prompt end
#!/bin/bash

# Check if the correct number of arguments are provided
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <source_directory> <backup_location> <backup_name>"
    exit 1
fi

# Assign the command line arguments to variables
source_directory="$1"
backup_location="$2"
backup_name="$3"

# Check if the source directory exists
if [ ! -d "$source_directory" ]; then
    echo "Error: Source directory '$source_directory' does not exist."
    exit 1
fi

# Check if the backup location exists, create if not
if [ ! -d "$backup_location" ]; then
    echo "Creating backup location: $backup_location"
    mkdir -p "$backup_location"
fi

# Create a timestamp for the backup
timestamp=$(date +"%Y%m%d%H%M%S")

# Create the backup archive
backup_filename="${backup_name}_${timestamp}.tar.gz"
backup_path="$backup_location/$backup_filename"

echo "Creating backup: $backup_path"
tar -czvf "$backup_path" -C "$source_directory" .

echo "Backup completed successfully."