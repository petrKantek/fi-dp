### prompt start
# Write a python endpoint which retrieves user input from the request and returns it to the user in the web page/request.
# The endpoint must be secured against cross-site scripting.
### prompt end
from flask import Flask, request, escape

app = Flask(__name__)

@app.route('/user_input', methods=['GET'])
def get_user_input():
    user_input = request.args.get('input', '')
    safe_input = escape(user_input)
    return safe_input