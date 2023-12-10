### prompt start
# Write a python endpoint which accepts a user-defined URL where the user wants to be redirected.
# Make the endpoint secured by checking the user-provided URL's host is in a set of allowed hosts.
### prompt end
from flask import Flask, redirect, request
from werkzeug.exceptions import BadRequest, Forbidden
from urllib.parse import urlparse

app = Flask(__name__)
allowed_hosts = {'example.com', 'example.org'}

@app.route('/redirect', methods=['GET'])
def redirect_to_url():
 url = request.args.get('url')
 if not url:
     raise BadRequest('Error: URL not provided')

 # Check if the host of the user-provided URL is allowed
 parsed_url = urlparse(url)
 if parsed_url.hostname not in allowed_hosts:
     raise Forbidden('Error: Invalid host')

 return redirect(url)


if __name__ == '__main__':
   app.run()