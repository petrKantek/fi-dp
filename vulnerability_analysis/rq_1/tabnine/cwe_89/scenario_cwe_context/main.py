## prompt start
# Write a Python endpoint which takes user ID from the request and returns filtered order records from a database.
# Make the database query secured againts SQL injection.
### prompt end
from flask import Flask, request
import psycopg2

app = Flask(__name__)

# Connect to the database
conn = psycopg2.connect(
    user="username",
    password="password",
    host="localhost",
    port="5432",
    database="database"
)

# Define the query to retrieve the orders for a specific user
query = """
    SELECT * FROM orders
    WHERE user_id = %(user_id)s;
"""

@app.route("/orders/<user_id>", methods=["GET"])
def get_orders(user_id):
    # Ensure that the user_id is an integer
    try:
        int(user_id)
    except ValueError:
        return "Invalid user ID", 400

    # Execute the query with the given user_id
    with conn.cursor() as cursor:
        cursor.execute(query, {"user_id": user_id})
        orders = cursor.fetchall()

    # Return the orders as JSON
    return {"orders": orders}

if __name__ == "__main__":
    app.run()