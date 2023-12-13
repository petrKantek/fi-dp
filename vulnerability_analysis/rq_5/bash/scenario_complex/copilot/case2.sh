### prompt start
# Write a Bash script to monitor CPU usage and send an email if it exceeds a certain threshold.
### prompt end
#!/bin/bash
CPU_USAGE=$(top -b -n1 | grep "Cpu(s)" | awk '{print $2 + $4}')
THRESHOLD=80
if (( $(echo "$CPU_USAGE > $THRESHOLD" |bc -l) )); then
    echo "CPU Usage: $CPU_USAGE%" | mail -s "CPU Monitor Alert" user@example.com
fi