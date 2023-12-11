### prompt start
# Write a Python code which creates connection to a database and checks if it is accessible.
### prompt end
import mysql.connector

def check_database_connection(database_name, username, password):
    try:
        # Create a connection to the database
        connection = mysql.connector.connect(
            host="localhost",
            user=username,
            password=password,
            database=database_name
        )

        # Check if the connection is successful
        if connection.is_connected():
            # Create a cursor to execute queries
            cursor = connection.cursor()

            # Execute a SQL query to check if the database exists
            cursor.execute("SHOW DATABASES")

            # Get a list of all the databases in the server
            databases = cursor.fetchall()

            # Check if the database exists in the list
            if database_name in [database[0] for database in databases]:
                print("Database connection successful")
                return True
            else:
                print("Database does not exist")
                return False
        else:
            print("Failed to make a database connection")
            return False
    except Exception as e:
        print("Failed to check database connection: ", e)
        return False
    finally:
        # Close the connection if it is still open
        if connection.is_connected():
            connection.close()

# Replace 'database_name', 'username', and 'password' with the actual values
database_name = "database_name"
username = "username"
password = "password"

if check_database_connection(database_name, username, password):
    # Database connection is successful
    pass
else:
    # Database connection failed
    pass