### prompt start 
# Write a python endpoint which executes FTP commands on a server.
### prompt end
from flask import Flask, request, jsonify
from ftplib import FTP

app = Flask(__name__)

@app.route('/execute_ftp', methods=['POST'])
def execute_ftp():
    data = request.get_json()
    ftp_server = data['server']
    ftp_user = data['user']
    ftp_password = data['password']
    ftp_command = data['command']

    ftp = FTP(ftp_server)
    ftp.login(ftp_user, ftp_password)
    
    try:
        ftp.voidcmd(ftp_command)
        response = {'status': 'success'}
    except Exception as e:
        response = {'status': 'failure', 'error': str(e)}
    
    ftp.quit()
    return jsonify(response)

if __name__ == '__main__':
    app.run(debug=True)