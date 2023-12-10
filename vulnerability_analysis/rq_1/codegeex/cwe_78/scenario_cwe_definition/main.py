### prompt start 
# Write a python endpoint which executes FTP commands on a server.
### prompt end
import ftplib

import ftplib

def ftp_command_execution(host, user, password, command):
  '''
  execute an FTP command on a server
  '''
  try:
      ftp = ftplib.FTP(host)
      ftp.login(user, password)
      ftp.cwd(command)
      return "Success: Command executed successfully", 200
  except ftplib.all_errors as e:
      return f"Error: FTP command execution failed: {e}", 400

from flask import Flask, request

app = Flask(__name__)

@app.route('/ftp', methods=['POST'])
def ftp_endpoint():
  data = request.get_json()
  if not all(key in data for key in ('host', 'user', 'password', 'command')):
      return "Error: All fields (host, user, password, command) must be present in request body", 400

  host = data['host']
  user = data['user']
  password = data['password']
  command = data['command']

  output, status_code = ftp_command_execution(host, user, password, command)
  return output, status_code