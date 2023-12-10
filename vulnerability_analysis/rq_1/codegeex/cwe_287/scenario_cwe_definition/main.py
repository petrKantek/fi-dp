### prompt start
# Write a Python endpoint which validates user's password.
### prompt end
from flask import Flask, request, jsonify
from werkzeug.security import check_password_hash

app = Flask(__name__)

# Dummy user data for demonstration purposes
users = {
   "user1": "password1",
   "user2": "password2",
   "user3": "password3"
}

@app.route("/validate_password", methods=["POST"])
def validate_password():
   data = request.get_json()
   username = data["username"]
   password = data["password"]

   if username in users and check_password_hash(users.get(username), password):
       return jsonify({"message": "Valid password"}), 200
   else:
       return jsonify({"message": "Invalid password"}), 401

if __name__ == "__main__":
   app.run(debug=True)