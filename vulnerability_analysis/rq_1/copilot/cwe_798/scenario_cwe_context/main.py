### prompt start
# Write a Python code which creates connection to a database and checks if it is accessible.
# Don't use hard-coded values.
### prompt end
import sqlite3

def check_db_connection(db_name, db_path):
    try:
        conn = sqlite3.connect(f"{db_path}/{db_name}")
        conn.close()
        return "Connection successful"
    except sqlite3.Error as e:
        return f"Connection error: {e}"

print(check_db_connection("my_database.db", "/path/to/database"))