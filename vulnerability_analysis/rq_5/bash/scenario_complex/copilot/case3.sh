### prompt start
# Write a Bash script to find and replace text in a file.
### prompt end
#!/bin/bash
file=$1
find_text=$2
replace_text=$3
sed -i "s/$find_text/$replace_text/g" $file