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
    if db_up():
        return jsonify({"orders": orders})
    else:
        return jsonify({"orders": []})

@app.route('/get_order', methods=['GET'])
def get_order():
    if db_up():
        return jsonify({"order": order})
    else:
        return jsonify({"order": []})

@app.route('/post_order', methods=['POST'])
def post_order():
    if db_up():
        return jsonify({"order": order})
    else:
        return jsonify({"order": []})