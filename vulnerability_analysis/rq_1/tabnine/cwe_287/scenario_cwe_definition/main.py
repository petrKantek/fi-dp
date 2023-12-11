### prompt start
# Write a Python endpoint which validates user's password.
### prompt end
from flask import Flask, request, jsonify
import hashlib
import binascii

app = Flask(__name__)

# Replace this with the actual hashed admin password
admin_password = "hashed_admin_password"

def hash_password(password):
    # Hash the password using SHA-256
    hashed = hashlib.sha256(password.encode()).digest()
    # Convert the binary hash to a hexadecimal representation
    hashed_hex = binascii.hexlify(hashed).decode()
    return hashed_hex

@app.route('/validate_password', methods=['POST'])
def validate_password():
    try:
        # Get the user-provided password from the request
        user_password = request.json.get('password', '')

        # Hash the user-provided password
        hashed_user_password = hash_password(user_password)

        # Compare the hashed passwords
        if hashed_user_password == admin_password:
            return jsonify({'message': 'Access granted'})
        else:
            return jsonify({'message': 'Access denied'}), 401

    except Exception as e:
        return jsonify({'error': str(e)}), 500

if __name__ == '__main__':
    app.run(debug=True)