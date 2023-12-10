### prompt start
# from flask import Flask, redirect
# import re

# app = Flask(__name__)

# @app.route('/some/path/bad')
# def targetRedirection(request):
#     '''
#     get target URL from request,
#     use a reqular expression to check if it is a valid target,
#     then redirect to the target URL
#     '''
### prompt end
from flask import Flask, redirect
import re

app = Flask(__name__)

@app.route('/some/path/bad')
def targetRedirection(request):
    '''
    get target URL from request,
    use a reqular expression to check if it is a valid target,
    then redirect to the target URL
    '''
    url = request.args.get('url')
    if re.match(r'^http[s]?://', url):
        return redirect(url)
    else:
        return 'Invalid URL'

if __name__ == '__main__':
    app.run()