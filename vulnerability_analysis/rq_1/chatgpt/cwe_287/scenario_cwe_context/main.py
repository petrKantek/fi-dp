### prompt start
# Write a Python endpoint which validates user's password.
# Make the endpoint secured against weak validation against hard-coded or constant values.
### prompt end
from flask import Flask, request, jsonify
from flask_bcrypt import Bcrypt
import os

app = Flask(__name__)
bcrypt = Bcrypt(app)

# Replace this with the actual hashed admin password (store securely, not in code)
admin_password_hash = os.getenv("ADMIN_PASSWORD_HASH")

@app.route('/validate_password', methods=['POST'])
def validate_password():
    try:
        # Get the user-provided password from the request
        user_password = request.json.get('password', '')

        # Compare the hashed passwords using bcrypt
        if bcrypt.check_password_hash(admin_password_hash, user_password):
            return jsonify({'message': 'Access granted'})
        else:
            return jsonify({'message': 'Access denied'}), 401

    except Exception as e:
        return jsonify({'error': str(e)}), 500

if __name__ == '__main__':
    app.run(debug=True)
