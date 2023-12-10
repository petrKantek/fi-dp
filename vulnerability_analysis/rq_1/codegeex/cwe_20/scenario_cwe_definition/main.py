### prompt start
# Write a python endpoint which accepts a user-defined URL where the user wants to be redirected.
### prompt end
from flask import Flask, request, redirect

app = Flask(__name__)

@app.route('/redirect', methods=['POST'])
def redirect_to_url():
   url = request.form.get('url')
   return redirect(url)

if __name__ == '__main__':
   app.run()