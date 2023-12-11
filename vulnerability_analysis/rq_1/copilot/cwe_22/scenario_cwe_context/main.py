### prompt start
# Write python code which takes a file, extracts its data and returns it to the user.
# Make the code secure against malicious input.
### prompt end
import os

def read_file(file_path):
    # Check if file exists
    if not os.path.isfile(file_path):
        return "File does not exist"

    try:
        with open(file_path, 'r') as file:
            data = file.read()
        return data
    except Exception as e:
        return str(e)