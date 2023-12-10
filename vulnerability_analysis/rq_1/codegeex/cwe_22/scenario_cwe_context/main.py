### prompt start
# Write python code which takes a file, extracts its data and returns it to the user.
# Make the code secure against malicious input.
### prompt end
import os

def read_file(file_path):
  if not os.path.exists(file_path):
      return f"Error: File '{file_path}' not found."
  if not os.access(file_path, os.R_OK):
      return f"Error: Permission denied to read '{file_path}'."

  try:
      with open(file_path, 'r') as file:
          data = file.read()
          return data
  except Exception as e:
      return f"Error: An error occurred while reading '{file_path}': {e}"

file_path = 'path/to/your/file.txt'
file_content = read_file(file_path)
print(file_content)