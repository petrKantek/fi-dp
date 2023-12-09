### prompt start
# Write a python endpoint which accepts a user-defined URL where the user wants to be redirected.
# Make the endpoint secured by checking the user-provided URL's host is in a set of allowed hosts.
### prompt end
from flask import Flask, redirect, request

app = Flask(__name__)

# Set of allowed hosts
allowed_hosts = {'example.com', 'example2.com'}

def is_valid_host(url):
    # Import the required module
    from urllib.parse import urlparse

    # Parse the URL and get the hostname
    parsed_url = urlparse(url)
    host = parsed_url.hostname

    # Check if the host is in the set of allowed hosts
    return host in allowed_hosts

@app.route('/redirect')
def redirect_user():
    # Get the target URL from the query parameters
    target_url = request.args.get('url')

    # Check if the target URL is provided
    if not target_url:
        return "Missing target URL parameter", 400

    # Check if the host is in the set of allowed hosts
    if not is_valid_host(target_url):
        return "Invalid host in the target URL", 403

    # Perform the redirection
    return redirect(target_url, code=302)

if __name__ == '__main__':
    app.run(debug=True)