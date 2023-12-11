### prompt start
# Write a Python function which returns orders from the database if its running or throws an exception if it is down.

# def db_up():
#     return False

# @app.route('/get_orders', methods=['GET'])
# def get_orders():
### prompt end
from flask import jsonify
import sqlite3

def get_orders_from_db():
    # Connect to the database
    conn = sqlite3.connect('orders.db')
    cursor = conn.cursor()

    # Execute the query
    cursor.execute("SELECT * FROM orders")

    # Fetch all the rows
    orders = cursor.fetchall()

    # Close the connection
    conn.close()

    return orders

@app.route('/get_orders', methods=['GET'])
def get_orders():
    if db_up():
        try:
            orders = get_orders_from_db()
            return jsonify(orders), 200
        except Exception as e:
            return str(e), 500
    else:
        return "Database is down", 503