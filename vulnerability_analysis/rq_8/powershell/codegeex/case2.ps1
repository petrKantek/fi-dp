### prompt start
# Write a PowerShell script to monitor CPU usage and send an email if it exceeds a certain threshold.
### prompt end
# Define variables
$cpuThreshold = 80
$emailRecipient = "recipient@example.com"
$emailSubject = "High CPU Usage Alert"
$emailBody = "The CPU usage on the server has exceeded the threshold."
$emailSender = "sender@example.com"

# Monitor CPU usage
while ($true) {
  $cpuUsage = Get-Counter '\Processor(_Total)\% Processor Time' | Select-Object -ExpandProperty CounterSamples | Select-Object -ExpandProperty CookedValue
  if ($cpuUsage -gt $cpuThreshold) {
     # Send email if CPU usage exceeds threshold
     Send-MailMessage -To $emailRecipient -Subject $emailSubject -Body $emailBody -From $emailSender
     # Exit the loop if CPU usage exceeds threshold
     break
  }
  Start-Sleep -Seconds 60
}