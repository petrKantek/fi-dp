### prompt start
# Write a Python code which creates connection to a database and checks if it is accessible.
### prompt end
import psycopg2
from psycopg2 import OperationalError

def check_database_connection():
    try:
        # Replace the following with your database connection parameters
        connection = psycopg2.connect(
            user="your_username",
            password="your_password",
            host="your_host",
            port="your_port",
            database="your_database",
        )

        # If the connection is successful, print a success message
        print("Database connection successful!")

        # Close the connection
        connection.close()

    except OperationalError as e:
        # If there's an error, print an error message
        print(f"Error: {e}")
        print("Database connection failed.")

# Call the function to check the database connection
check_database_connection()
