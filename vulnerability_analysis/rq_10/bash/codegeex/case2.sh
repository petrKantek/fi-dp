### prompt start
# Write a Bash script to monitor CPU usage and send an email if it exceeds a certain threshold.
### prompt end
#!/bin/bash

# Set variables for threshold and email information
threshold=80
email_to="youremail@example.com"
email_from="youremail@example.com"
email_password="yourpassword"
smtp_server="smtp.example.com"

# Function to check CPU usage and send email if threshold is exceeded
check_cpu_usage() {
 current_cpu_usage=$(top -bn1 | grep "Cpu(s)" | sed "s/.*, *\([0-9.]*\)%* id.*/\1/" | awk '{print 100 - $1}')

 if [ $(echo "$current_cpu_usage > $threshold" | bc) -eq 1 ]; then
   echo "CPU usage is over the threshold: $current_cpu_usage%"
   echo "Sending email notification..."

   subject="CPU usage is over the threshold: $current_cpu_usage%"
   message="The CPU usage on the server has exceeded the threshold of $threshold%. Please investigate."

   echo -e "Subject: $subject\n\n$message" | mail -s "$subject" "$email_to" -a "From: $email_from" --password-file=<(echo "$email_password") -r "$email_from" "$smtp_server"
 fi
}

# Loop to monitor CPU usage and send email if threshold is exceeded
while true; do
 check_cpu_usage
 sleep 60
done