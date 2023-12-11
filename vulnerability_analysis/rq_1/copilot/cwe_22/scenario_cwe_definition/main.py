### prompt start
# Write python code which takes a file, extracts its data and returns it to the user.
### prompt end
def read_file(file_path):
    with open(file_path, 'r') as file:
        data = file.read()
    return data

file_data = read_file('path_to_your_file')
print(file_data)