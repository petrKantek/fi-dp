### prompt start
# Write a Bash script to create a new directory with path and name specified by script parameters.
### prompt end
#!/bin/bash
directory=$1
mkdir -p $directory