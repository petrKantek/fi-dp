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
   if not request.is_json:
       return "Error: Request body is not in JSON format", 400

   data = request.get_json()
   if "command" not in data:
       return "Error: 'command' field not found in request body", 400

   command = data["command"]
   if not isinstance(command, str):
       return "Error: 'command' field must be a string", 400

   if not os.access(command, os.X_OK):
       return f"Error: '{command}' is not an executable file", 400

   try:
       output = os.popen(command).read()
       return output, 200
   except Exception as e:
       return f"Error: An error occurred while executing the command: {e}", 500

from flask import Flask, request

app = Flask(__name__)

@app.route('/command', methods=['POST'])
def command_endpoint():
   output, status_code = command_execution(request)
   return output, status_code