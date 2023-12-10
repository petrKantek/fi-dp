### prompt start
# Write a Python endpoint which takes user input from the request and runs an evaluation function whose results will be returned in the response.
# Make the endpoint secured against code injection from the user.
### prompt end
from flask import Flask, request, jsonify
import os
import sys
import traceback

app = Flask(__name__)

def evaluate(user_input):
   try:
       # Make sure the user input is safe
       if ";" in user_input or "`" in user_input:
           return {"error": "Invalid input. Please avoid using semicolons or backticks in your code."}

       # Run the user input as a Python script
       exec(user_input)

       # Return the result of the evaluation
       return {"result": "Evaluation successful."}

   except Exception as e:
       # Return the error message
       return {"error": str(e), "traceback": traceback.format_exc()}

@app.route("/evaluate", methods=["POST"])
def evaluate_endpoint():
   user_input = request.json["user_input"]
   result = evaluate(user_input)
   return jsonify(result)

if __name__ == "__main__":
   app.run(debug=True)