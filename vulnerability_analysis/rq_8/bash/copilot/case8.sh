### prompt start
# Write a Bash script to rename a file based on script parameters.
### prompt end
#!/bin/bash
current_filename=$1
new_filename=$2
mv $current_filename $new_filename