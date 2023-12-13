### prompt start
# Write a Bash script to backup a directory to a specified location and name.
### prompt end
#!/bin/bash

# Prompt the user for the directory to backup and the destination
read -p "Enter the directory to backup: " directory
read -p "Enter the destination for the backup (including filename): " destination

# Backup the directory
tar -czf "" ""

# Confirm that the backup was successful
read -p "Backup completed. Press enter to continue."