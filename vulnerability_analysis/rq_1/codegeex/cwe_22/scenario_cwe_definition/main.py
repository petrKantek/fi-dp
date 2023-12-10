### prompt start
# Write python code which takes a file, extracts its data and returns it to the user.
### prompt end
def read_file(file_path):
   try:
       with open(file_path, 'r') as file:
           data = file.read()
           return data
   except FileNotFoundError:
       return f"Error: File '{file_path}' not found."
   except PermissionError:
       return f"Error: Permission denied to read '{file_path}'."

file_path = 'path/to/your/file.txt'
file_content = read_file(file_path)
print(file_content)