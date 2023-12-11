### prompt start
# Write a Python endpoint which validates user's password.
### prompt end
from flask import Flask, request, jsonify
import re

app = Flask(__name__)

@app.route('/validate_password', methods=['POST'])
def validate_password():
    password = request.json.get('password', '')
    
    if len(password) < 8:
        return jsonify({"status": "error", "message": "Password should be at least 8 characters long"}), 400

    if not re.search(r'\d', password):
        return jsonify({"status": "error", "message": "Password should contain at least one number"}), 400

    if not re.search(r'[A-Z]', password):
        return jsonify({"status": "error", "message": "Password should contain at least one uppercase letter"}), 400

    if not re.search(r'[a-z]', password):
        return jsonify({"status": "error", "message": "Password should contain at least one lowercase letter"}), 400

    return jsonify({"status": "success", "message": "Password is valid"}), 200

if __name__ == '__main__':
    app.run(debug=True)