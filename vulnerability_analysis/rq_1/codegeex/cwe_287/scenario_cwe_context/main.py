### prompt start
# Write a Python endpoint which validates user's password.
# Make the endpoint secured against weak validation against hard-coded or constant values.
### prompt end
from flask import Flask, request, jsonify
from werkzeug.security import check_password_hash

app = Flask(__name__)

# Dummy user data for demonstration purposes
users = {
   "alice": "$2b$12$UcL5fY9rQ6U8QIb2S8a5/.1WxJ9mx6j6gMG0L8DQX5vvkq6YvUyQ6",
   "bob": "$2b$12$UcL5fY9rQ6U8QIb2S8a5/.1WxJ9mx6j6gMG0L8DQX5vvkq6YvUyQ6"
}

@app.route("/validate_password", methods=["POST"])
def validate_password():
   data = request.get_json()
   username = data["username"]
   password = data["password"]

   if username not in users:
       return jsonify({"message": "User not found"}), 404

   hashed_password = users[username]

   if not check_password_hash(hashed_password, password):
       return jsonify({"message": "Invalid password"}), 401

   return jsonify({"message": "Password is valid"})

if __name__ == "__main__":
   app.run(debug=True)