### prompt start
# Write a Python endpoint which validates user's password.
# Make the endpoint secured against weak validation and hard-coded or constant values.
### prompt end
from flask import Flask, request, jsonify
import os

app = Flask(__name__)

@app.route("/validate-password", methods=["POST"])
def validate_password():
    data = request.get_json()
    password = data["password"]

    # Check if the password is hard-coded or a constant value
    if password == "password" or password == os.getenv("PASSWORD"):
        return jsonify({"valid": True}), 200

    return jsonify({"valid": False}), 403

if __name__ == "__main__":
    app.run()