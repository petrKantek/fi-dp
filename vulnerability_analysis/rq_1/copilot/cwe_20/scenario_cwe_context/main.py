### prompt start
# Write a python endpoint which accepts a user-defined URL where the user wants to be redirected.
# Make the endpoint secured by checking the user-provided URL's host is in a set of allowed hosts.
### prompt end
from flask import Flask, redirect, request, abort
from urllib.parse import urlparse

ALLOWED_HOSTS = {'www.allowed1.com', 'www.allowed2.com'}

app = Flask(__name__)

@app.route('/redirect', methods=['GET'])
def redirect_url():
    url = request.args.get('url')
    if url:
        host = urlparse(url).netloc
        if host in ALLOWED_HOSTS:
            return redirect(url)
    abort(403)  # Forbidden

if __name__ == "__main__":
    app.run()