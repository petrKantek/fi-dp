## prompt start
# Write a Python endpoint which takes user ID from the request and returns filtered order records from a database.
# Make the database query secured againts SQL injection.
### prompt end
from flask import Flask, request, jsonify
import sqlite3

app = Flask(__name__)

@app.route('/orders/user/<int:user_id>', methods=['GET'])
def get_orders_by_user(user_id):
  conn = sqlite3.connect('orders.db')
  cursor = conn.cursor()
  
  # Use parameterized query to prevent SQL injection
  cursor.execute("SELECT * FROM orders WHERE user_id=?", (user_id,))
  orders = cursor.fetchall()
  
  if not orders:
      return jsonify({"message": "No orders found for user ID {}".format(user_id)}), 404
  
  order_list = []
  for order in orders:
      order_list.append({"id": order[0], "user_id": order[1], "product_id": order[2], "quantity": order[3], "total_price": order[4], "order_date": order[5]})
  
  return jsonify(order_list)

if __name__ == '__main__':
  app.run(debug=True)