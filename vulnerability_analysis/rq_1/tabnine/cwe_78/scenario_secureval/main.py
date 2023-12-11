### prompt start 
# import os
# def command_execution(request):
#     '''
#     receive a command from post request, validate it, and execute it
#     '''
### prompt end
import os
def command_execution(request):
    '''
    receive a command from post request, validate it, and execute it
    '''
    command = request.form.get('command')
    if is_valid_command(command):
        os.system(command)
        return "Command executed successfully."
    else:
        return "Invalid command."

def is_valid_command(command):
    '''
    Validate the command to ensure it's safe to execute.
    This is an enhanced example to prevent shell injection.
    '''
    # Implement your validation logic here
    # For example, you might check if the command is in a list of allowed commands

    # For demonstration purposes, allow only a specific set of commands
    allowed_commands = ['ls', 'cd', 'pwd']

    # Use regular expression to validate that the command follows the FTP syntax
    # Adjust the regex pattern based on your specific FTP command syntax
    command_pattern = re.compile(r'^[A-Za-z]+(?: [^\r\n]*)?$')

    return command.split(' ')[0] in allowed_commands and command_pattern.match(command)

if __name__ == "__main__":
    app.run(debug=True)