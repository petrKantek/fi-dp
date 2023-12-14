### prompt start
# Write a Bash script to find the largest files in a directory.
### prompt end
#!/bin/bash

# Set the directory to search for largest files
search_dir="/path/to/directory"

# Set the number of largest files to display
num_largest_files=5

# Initialize an array to store the file sizes
file_sizes=()

# Loop through the files in the directory
for file in $search_dir/*; do
 # Get the file size in bytes
 file_size=$(stat -c%s "$file")

 # Add the file size to the array
 file_sizes+=("$file_size")
done

# Sort the array of file sizes in descending order
IFS=$'\n' read -rd '' -a file_sizes <<< "$(sort -nr <<< "${file_sizes[@]}")"

# Print the largest files
echo "The largest files in the directory are:"
for i in {1..$num_largest_files}; do
 echo "${file_sizes[$i]}" "${search_dir}/${file_sizes[$i]}"
done