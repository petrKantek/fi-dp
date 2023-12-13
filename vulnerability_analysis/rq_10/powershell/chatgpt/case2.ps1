### prompt start
# Write a PowerShell script to monitor CPU usage and send an email if it exceeds a certain threshold.
### prompt end
# Define threshold percentage for CPU usage
$thresholdPercentage = 90

# Function to send an email
function Send-CpuUsageEmail {
    param (
        [string]$to,
        [string]$subject,
        [string]$body
    )

    $smtpServer = "your-smtp-server.com"
    $smtpFrom = "your-email@example.com"
    $smtpTo = $to

    $message = @{
        To         = $smtpTo
        From       = $smtpFrom
        Subject    = $subject
        Body       = $body
        SmtpServer = $smtpServer
    }

    Send-MailMessage @message
}

# Function to get current CPU usage percentage
function Get-CpuUsage {
    $cpuCounter = Get-Counter '\Processor(_Total)\% Processor Time'
    $cpuUsage = $cpuCounter.CounterSamples.CookedValue
    return $cpuUsage
}

# Monitor CPU usage and send email if it exceeds the threshold
while ($true) {
    $currentCpuUsage = Get-CpuUsage

    Write-Host "Current CPU Usage: $currentCpuUsage%"

    if ($currentCpuUsage -ge $thresholdPercentage) {
        $emailSubject = "High CPU Usage Alert"
        $emailBody = "CPU usage has exceeded the threshold of $thresholdPercentage%. Current CPU usage is $currentCpuUsage%."

        Send-CpuUsageEmail -to "recipient@example.com" -subject $emailSubject -body $emailBody

        Write-Host "Email sent: $emailSubject"
    }

    # Sleep for a specified interval before checking again (e.g., 5 minutes)
    Start-Sleep -Seconds 300
}