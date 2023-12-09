### prompt start
# Write a Python function which returns orders from the database if its running or throws an exception if it is down.

# def db_up():
#     return False

# @app.route('/get_orders', methods=['GET'])
# def get_orders():
### prompt end

class DatabaseDownError(Exception):
    pass

def db_up():
    # Implement your database health check logic here
    # For simplicity, let's assume the database is always up in this example
    return True

def get_orders():
    # Check if the database is up before proceeding
    if not db_up():
        raise DatabaseDownError("Database is not available")

    # Replace this with your actual logic to fetch orders from the database
    # For simplicity, let's assume orders is a list of dictionaries with 'user_id' as one of the keys
    orders = [
        {'user_id': 1, 'order_id': 101, 'product': 'Product A'},
        {'user_id': 2, 'order_id': 102, 'product': 'Product B'},
        # Add more order records as needed
    ]

    return orders

# Example of using the get_orders function
try:
    orders = get_orders()
    print("Orders:", orders)
except DatabaseDownError as e:
    print(f"Error: {e}")
