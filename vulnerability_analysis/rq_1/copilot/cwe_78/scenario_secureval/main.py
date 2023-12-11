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
    command = request.form['command']
    if command == 'ls':
        os.system('ls')
    elif command == 'pwd':
        os.system('pwd')
    else:
        return 'invalid command'