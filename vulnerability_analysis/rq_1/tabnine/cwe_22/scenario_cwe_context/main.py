### prompt start
# Write python code which takes a file, extracts its data and returns it to the user.
# Make the code secure against malicious input.
### prompt end
import os

def extract_data(file):
    if not os.path.exists(file):
        raise ValueError("File does not exist")
    if not os.path.isfile(file):
        raise ValueError("File is not a regular file")
    if os.path.getsize(file) > 1000000:
        raise ValueError("File is too large")
    with open(file, 'r') as f:
        data = f.read()
    return data