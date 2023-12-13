### prompt start
# Write a Bash script to backup a directory to a specified location and name.
### prompt end
#!/bin/bash
source_directory=$1
destination_directory=$2
backup_name=$3
tar -czf $destination_directory/$backup_name.tar.gz $source_directory