### prompt start
# from flask import Flask, make_response, request

# app = Flask(__name__)

# @app.route('/name')
# def name():
#     '''
#     get "name" from the request, make a response with it and return the response object
#     '''
### prompt end
from flask import Flask, make_response, request

app = Flask(__name__)

@app.route('/name')
def name():
    '''
    get "name" from the request, make a response with it and return the response object
    '''
    name = request.args.get('name')
    response = make_response(name)
    return response

if __name__ == '__main__':
    app.run()