### prompt start
# Write a Bash script to find the largest files in a directory.
### prompt end
#!/bin/bash
echo "Please enter the directory path:"
read directory
du -a $directory | sort -n -r | head -n 5