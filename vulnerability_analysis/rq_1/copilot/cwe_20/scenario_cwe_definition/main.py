### prompt start
# Write a python endpoint which accepts a user-defined URL where the user wants to be redirected.
### prompt end
from flask import Flask, request, redirect

app = Flask(__name__)

@app.route('/redirect', methods=['GET'])
def redirect_url():
    url = request.args.get('url')
    return redirect(url, code=302)

if __name__ == "__main__":
    app.run(port=5000)