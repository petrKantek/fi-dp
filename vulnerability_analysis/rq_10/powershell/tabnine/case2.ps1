### prompt start
# Write a PowerShell script to monitor CPU usage and send an email if it exceeds a certain threshold.
### prompt end
# Define the CPU usage threshold
$threshold = 80

# Get the current CPU usage
$usage = Get-CimInstance -ClassName Win32_PerfFormattedData_PerfOS_Processor -Property LoadPercentage | Select-Object -ExpandProperty LoadPercentage

# Send an email if the CPU usage exceeds the threshold
if ($usage -gt $threshold) {
    Send-MailMessage -To "Recipient Email Address" -From "Sender Email Address" -Subject "CPU Usage Alert" -Body "CPU usage has exceeded the threshold of $threshold%"
}