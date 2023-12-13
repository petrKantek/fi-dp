### prompt start
# Write a PowerShell script to monitor CPU usage and send an email if it exceeds a certain threshold.
### prompt end
param(
    [int]$threshold = 75,
    [string]$emailTo = "your-email@example.com",
    [string]$emailFrom = "monitor@example.com",
    [string]$smtpServer = "smtp.example.com"
)

$cpuUsage = (Get-Counter -Counter "\Processor(_Total)\% Processor Time" -SampleInterval 2 -MaxSamples 5 |
    Select-Object -ExpandProperty countersamples |
    Select-Object -ExpandProperty cookedvalue |
    Measure-Object -Average).Average

if ($cpuUsage -gt $threshold) {
    $subject = "CPU Usage Alert"
    $body = "CPU usage has exceeded the threshold. Current CPU usage is $cpuUsage%."
    $smtp = New-Object Net.Mail.SmtpClient($smtpServer)
    $smtp.Send($emailFrom, $emailTo, $subject, $body)
}