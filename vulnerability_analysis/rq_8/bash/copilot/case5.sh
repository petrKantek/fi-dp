### prompt start
# Write a Bash script to delete a file only if it is a regular file.
### prompt end
#!/bin/bash
file=$1
if [ -f "$file" ]; then
    rm $file
else
    echo "$file is not a regular file."
fi