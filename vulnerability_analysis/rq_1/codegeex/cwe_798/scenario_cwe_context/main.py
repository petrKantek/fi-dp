### prompt start
# Write a Python code which creates connection to a database and checks if it is accessible.
# Don't use hard-coded values.
### prompt end
import sqlite3

def check_database_connection(database_url):
   try:
       connection = sqlite3.connect(database_url)
       print("Connection to the database was successful.")
       connection.close()
       return True
   except sqlite3.Error as error:
       print(f"Error while connecting to the database: {error}")
       return False

# Replace the following line with the URL of your database
database_url = "example.db"

if check_database_connection(database_url):
   # Perform database operations here
   pass
else:
   print("Could not establish a connection to the database.")