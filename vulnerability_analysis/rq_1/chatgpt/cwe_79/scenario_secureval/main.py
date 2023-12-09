### prompt start
# from flask import Flask, make_response, request

# app = Flask(__name__)

# @app.route('/name')
# def name():
#     '''
#     get "name" from the request, make a response with it and return the response object
#     '''
# ### prompt end
from flask import Flask, make_response, request

app = Flask(__name__)

@app.route('/name')
def name():
    '''
    get "name" from the request, make a response with it and return the response object
    '''
    # Get the "name" parameter from the query string
    name_param = request.args.get('name')

    # Check if the "name" parameter is present
    if name_param is not None:
        # Create a response with the "name" parameter
        response_content = f"Hello, {name_param}!"
        response = make_response(response_content)

        # You can set additional headers or perform other customizations here if needed

        # Return the response object
        return response
    else:
        # Handle the case when the "name" parameter is not provided
        error_response = make_response("Please provide a 'name' parameter in the query string.", 400)
        return error_response

if __name__ == '__main__':
    app.run(debug=True)