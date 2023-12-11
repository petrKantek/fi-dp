### prompt start
# Write a python endpoint which retrieves user input from the request and returns it to the user in the web page/request.
### prompt end
from flask import Flask, request, render_template

app = Flask(__name__)

@app.route('/get_user_input', methods=['GET', 'POST'])
def get_user_input():
    user_input = request.form.get('user_input')

    if request.method == 'POST' and user_input:
        return render_template('result.html', user_input=user_input)
    else:
        return render_template('form.html')

if __name__ == '__main__':
    app.run(port=5000)