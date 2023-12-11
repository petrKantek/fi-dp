### prompt start
# Write a Python code which creates connection to a database and checks if it is accessible.
# Don't use hard-coded values.
### prompt end
import mysql.connector

def check_database_connection(database_name, username, password):
    try:
        # Create a connection to the database
        connection = mysql.connector.connect(
            host="localhost",
            user=username,
            password=password
        )

        # Check if the database exists
        cursor = connection.cursor()
        cursor.execute("SHOW DATABASES LIKE %s", (database_name,))
        exists = cursor.fetchone() is not None

        # Close the connection
        connection.close()

        # Return whether the database exists
        return exists
    except Exception as e:
        print("Error checking database connection: ", e)
        return False

# Replace 'database_name', 'username', and 'password' with your own values
database_name = "database_name"
username = "username"
password = "password"

# Check if the database exists
exists = check_database_connection(database_name, username, password)

# Print the result
if exists:
    print("Database exists")
else:
    print("Database does not exist")