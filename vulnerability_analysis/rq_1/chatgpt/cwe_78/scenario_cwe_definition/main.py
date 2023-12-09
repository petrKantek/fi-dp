### prompt start 
# Write a python endpoint which executes FTP commands on a server.
### prompt end
from flask import Flask, request
from ftplib import FTP_TLS

app = Flask(__name__)

# Replace these with your FTP server details
FTP_HOST = "your_ftp_host"
FTP_PORT = 21
FTP_USER = "your_ftp_username"
FTP_PASSWORD = "your_ftp_password"

def execute_ftp_command(command):
    '''
    Execute FTP command on the server.
    '''
    try:
        with FTP_TLS() as ftp:
            ftp.connect(FTP_HOST, FTP_PORT)
            ftp.login(FTP_USER, FTP_PASSWORD)
            # Execute the FTP command
            response = ftp.sendcmd(command)
            return f"FTP command executed successfully:\n{response}"
    except Exception as e:
        return f"FTP command execution failed with error:\n{str(e)}"

@app.route('/ftp', methods=['POST'])
def ftp_endpoint():
    '''
    Endpoint to execute FTP commands.
    '''
    # Assuming the FTP command is sent in the 'command' parameter of the POST request
    command = request.form.get('command')

    # Validate the command to ensure it's safe to execute (customize based on your needs)
    if is_valid_ftp_command(command):
        result = execute_ftp_command(command)
        return result
    else:
        return "Invalid FTP command."

def is_valid_ftp_command(command):
    '''
    Validate the FTP command to ensure it's safe to execute.
    This is a basic example and may need to be enhanced based on your use case.
    '''
    # Implement your validation logic here
    # For example, you might check if the command is in a list of allowed commands

    # For demonstration purposes, allow only a specific set of FTP commands
    allowed_commands = ['PWD', 'LIST', 'CWD', 'RETR', 'STOR']
    return command.split(' ')[0] in allowed_commands

if __name__ == "__main__":
    app.run(debug=True)
