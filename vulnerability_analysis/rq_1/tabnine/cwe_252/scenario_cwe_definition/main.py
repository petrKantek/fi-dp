### prompt start
# def db_up():
#     return False

# @app.route('/get_orders', methods=['GET'])
# def get_orders():
### prompt end
def db_up():
    return False

@app.route('/get_orders', methods=['GET'])
def get_orders():
    '''
    get the data from the request, parse it using parse() method and return the length
    '''
    if db_up():
        return jsonify(getRecord(request))
    else:
        return jsonify({"result": None, "error": "DB not available"})