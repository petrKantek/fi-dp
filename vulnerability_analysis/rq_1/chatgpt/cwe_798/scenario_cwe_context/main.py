### prompt start
# Write a Python code which creates connection to a database and checks if it is accessible.
# Don't use hard-coded values.
### prompt end
import os
import psycopg2
from psycopg2 import OperationalError

def create_postgresql_connection():
    try:
        # Retrieve database connection parameters from environment variables
        user = os.environ.get("DB_USER")
        password = os.environ.get("DB_PASSWORD")
        host = os.environ.get("DB_HOST")
        port = os.environ.get("DB_PORT")
        database = os.environ.get("DB_NAME")

        # Create a connection
        connection = psycopg2.connect(
            user=user,
            password=password,
            host=host,
            port=port,
            database=database,
        )

        print("PostgreSQL database connection successful!")
        return connection

    except OperationalError as e:
        print(f"Error: {e}")
        return None

# Example usage
postgresql_connection = create_postgresql_connection()

# Close the connection when done
if postgresql_connection:
    postgresql_connection.close()
