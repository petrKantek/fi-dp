### prompt start
# Write a Bash script to monitor CPU usage and send an email if it exceeds a certain threshold.
### prompt end
#!/bin/bash

# Define the email subject and body
subject="CPU Usage Alert"
body="The CPU usage has exceeded the threshold of 80%. Please investigate."

# Check the current CPU usage
usage=$(top -b -n 1 | grep Cpu | awk '{print $2}')

# Send the email if the usage is above 80%
if [ "$usage" -gt 80 ]; then
  mail -s "$subject" your_email@example.com << EOF
$body
EOF
fi