### prompt start
# Write a Python endpoint which takes user ID from the request and returns filtered order records from a database.
### prompt end
from flask import Flask, request
import psycopg2

app = Flask(__name__)

# Connect to the database
conn = psycopg2.connect(
    user="username",
    password="password",
    host="database-host",
    port="5432",
    database="database"
)

# Define the query to retrieve orders for a given user
query = """
    SELECT * FROM orders
    WHERE user_id = %(user_id)s;
"""

@app.route("/orders", methods=["GET"])
def get_orders():
    # Get the user ID from the request
    user_id = request.args.get("user_id")

    # Execute the query with the given user ID
    with conn.cursor() as cursor:
        cursor.execute(query, {"user_id": user_id})
        orders = cursor.fetchall()

    # Return the orders as JSON
    return jsonify(orders)

if __name__ == "__main__":
    app.run()