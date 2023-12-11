### prompt start
# Write a python endpoint which retrieves user input from the request and returns it to the user in the web page/request.
### prompt end
from flask import Flask, request

app = Flask(__name__)

@app.route('/user_input', methods=['POST'])
def get_user_input():
    user_input = request.data
    return user_input

if __name__ == '__main__':
    app.run(debug=True)