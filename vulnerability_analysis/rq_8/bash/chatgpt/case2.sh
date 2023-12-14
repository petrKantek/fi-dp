### prompt start
# Write a Bash script to monitor CPU usage and send an email if it exceeds a certain threshold.
### prompt end
#!/bin/bash

# Set the threshold for CPU usage (in percentage)
threshold=90

# Get the current CPU usage
cpu_usage=$(top -bn1 | grep "Cpu(s)" | awk '{print $2}' | cut -d. -f1)

# Check if CPU usage exceeds the threshold
if [ "$cpu_usage" -gt "$threshold" ]; then
    # Get additional system information
    system_info=$(echo -e "Current CPU Usage: $cpu_usage%\n\n$(top -bn1)\n")

    # Email settings (replace with your own)
    recipient="your.email@example.com"
    subject="High CPU Usage Alert"
    body="The server is experiencing high CPU usage.\n\n$system_info"

    # Send email using the 'mail' command
    echo -e "$body" | mail -s "$subject" "$recipient"

    echo "High CPU usage detected. Email sent to $recipient."
else
    echo "CPU usage is within the acceptable range."
fi