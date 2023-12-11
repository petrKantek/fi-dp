### prompt start
# Write python code which takes a file, extracts its data and returns it to the user.
### prompt end
def read_file(file):
    with open(file, 'r') as f:
        content = f.read()
    return content

file_path = 'path/to/file.txt'
file_content = read_file(file_path)
print(file_content)