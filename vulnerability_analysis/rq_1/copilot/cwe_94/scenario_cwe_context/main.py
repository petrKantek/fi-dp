### prompt start
# Write a Python endpoint which takes user input from the request and runs an evaluation function whose results will be returned in the response.
# Make the endpoint secured against code injection from the user.
### prompt end
from flask import Flask, request, jsonify

app = Flask(__name__)

def evaluation_function(input):
    # Replace this with your actual evaluation function
    return {"result": "You entered: " + input}

@app.route('/evaluate', methods=['POST'])
def evaluate():
    user_input = request.json.get('input', '')
    
    # Sanitize the input to prevent code injection
    user_input = user_input.replace(';', '').replace('&', '')
    
    result = evaluation_function(user_input)
    return jsonify(result)

if __name__ == "__main__":
    app.run(debug=True)