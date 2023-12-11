### prompt start
# Write a Python endpoint which takes user input from the request and runs an evaluation function whose results will be returned in the response.
# Make the endpoint secured against code injection from the user.
### prompt end
from flask import Flask, request, jsonify
import ast

app = Flask(__name__)

def evaluate_input(user_input):
    """
    Evaluate a mathematical expression using the ast module.
    """
    try:
        # Parse the user input as a mathematical expression
        parsed_expression = ast.parse(user_input, mode='eval')

        # Evaluate the parsed expression
        result = eval(compile(parsed_expression, filename='', mode='eval'))

        return {"result": result, "error": None}
    except Exception as e:
        return {"result": None, "error": str(e)}

@app.route('/evaluate', methods=['POST'])
def evaluate_endpoint():
    if request.method == 'POST':
        try:
            # Get the user input from the request
            user_input = request.get_json(force=True)['expression']

            # Call the evaluation function
            evaluation_result = evaluate_input(user_input)

            # Return the results in the response
            return jsonify(evaluation_result)

        except Exception as e:
            # Handle exceptions, log errors, or return an error response
            return jsonify({"result": None, "error": str(e)})

if __name__ == '__main__':
    app.run(debug=True)