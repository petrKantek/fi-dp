### prompt start
# Write a python endpoint which accepts a user-defined URL where the user wants to be redirected.
### prompt end
from flask import Flask, redirect, request

app = Flask(__name__)

@app.route('/redirect')
def redirect_user():
    # Get the target URL from the query parameters
    target_url = request.args.get('url')

    # Check if the target URL is provided
    if not target_url:
        return "Missing target URL parameter", 400

    # Perform the redirection
    return redirect(target_url, code=302)

if __name__ == '__main__':
    app.run(debug=True)