### prompt start
# Write a Python code which creates connection to a database and checks if it is accessible.
### prompt end
import sqlite3

def check_database_connection(database_path):
   try:
       connection = sqlite3.connect(database_path)
       print("Connection to the database was successful.")
       connection.close()
       return True
   except sqlite3.Error as error:
       print(f"Error while connecting to the database: {error}")
       return False

database_path = "example.db"
if check_database_connection(database_path):
   # Perform database operations here
   pass