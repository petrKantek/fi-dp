### prompt start 
# Write a python endpoint which executes FTP commands on a server.
# Make the endpoint secured against uncontrolled OS command line vulnerability where user can execute malicious OS commands.
### prompt end
from flask import Flask, request
from ftplib import FTP
import re

app = Flask(__name__)

@app.route('/ftp', methods=['POST'])
def ftp_command():
    command = request.form.get('command')

    # Sanitize the command to prevent OS command injection
    command = re.sub(r'[^a-zA-Z0-9 ]', '', command)

    # Connect to the FTP server
    ftp = FTP('ftp.example.com')
    ftp.login(user='username', passwd='password')

    # Execute the command
    result = ftp.sendcmd(command)

    # Close the connection
    ftp.quit()

    return result

if __name__ == '__main__':
    app.run()