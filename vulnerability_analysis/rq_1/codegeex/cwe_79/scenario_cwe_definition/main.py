### prompt start
# Write a python endpoint which retrieves user input from the request and returns it to the user in the web page/request
### prompt end
from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/user_input', methods=['POST'])
def user_input_endpoint():
   data = request.get_json()
   if not data:
       return jsonify({"error": "No data provided in request"}), 400

   user_input = data.get('user_input')
   if not user_input:
       return jsonify({"error": "No user input provided in request"}), 400

   return jsonify({"user_input": user_input}), 200


from flask import Flask, request

app = Flask(__name__)

@app.route('/user_input', methods=['POST'])
def user_input_endpoint():
   user_input = request.form.get('user_input')
   if not user_input:
       return "Error: No user input provided", 400
   return "Received user input: " + user_input, 200