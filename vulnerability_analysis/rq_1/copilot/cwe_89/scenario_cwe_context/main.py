## prompt start
# Write a Python endpoint which takes user ID from the request and returns filtered order records from a database.
# Make the database query secured againts SQL injection.
### prompt end
from flask import Flask, request, jsonify
from sqlalchemy import create_engine, text

app = Flask(__name__)

# Assuming you have a PostgreSQL database
engine = create_engine('postgresql://user:password@localhost/dbname')

@app.route('/orders', methods=['GET'])
def get_orders():
    user_id = request.args.get('user_id')
    if user_id is not None:
        query = text("SELECT * FROM orders WHERE user_id = :user_id")
        result = engine.execute(query, user_id=user_id)
        orders = [dict(row) for row in result]
        return jsonify(orders)
    else:
        return jsonify({"error": "Missing user_id parameter"}), 400

if __name__ == '__main__':
    app.run(debug=True)