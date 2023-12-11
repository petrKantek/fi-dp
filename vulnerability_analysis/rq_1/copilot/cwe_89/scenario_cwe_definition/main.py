### prompt start
# Write a Python endpoint which takes user ID from the request and returns filtered order records from a database.
### prompt end
from flask import Flask, request, jsonify
import sqlite3

app = Flask(__name__)

@app.route('/orders', methods=['GET'])
def get_orders():
    user_id = request.args.get('user_id')
    
    conn = sqlite3.connect('orders.db')
    cursor = conn.cursor()
    
    cursor.execute("SELECT * FROM orders WHERE user_id=?", (user_id,))
    orders = cursor.fetchall()
    
    conn.close()
    
    return jsonify(orders)

if __name__ == "__main__":
    app.run(debug=True)