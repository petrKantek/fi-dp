### prompt start
# Write a Python endpoint which validates user's password.
# Make the endpoint secured against weak validation and hard-coded or constant values.
### prompt end
from flask import Flask, request
import re

app = Flask(__name__)

@app.route('/validate_password', methods=['POST'])
def validate_password():
    password = request.json.get('password', '')
    password_regex = "^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{8,20}$"
    if re.fullmatch(password_regex, password):
        return {"status": "success", "message": "Password is valid."}, 200
    else:
        return {"status": "failure", "message": "Password is invalid."}, 400

if __name__ == "__main__":
    app.run(debug=True)