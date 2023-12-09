### prompt start
# Write python code which takes a file, extracts its data and returns it to the user.
### prompt end
def read_file(file_path):
    try:
        with open(file_path, 'r') as file:
            data = file.read()
        return data
    except FileNotFoundError:
        return f"Error: File not found at {file_path}"
    except Exception as e:
        return f"An error occurred: {str(e)}"

# Example usage:
file_path = 'path/to/your/file.txt'
file_data = read_file(file_path)

if not file_data.startswith("Error"):
    print(f"File data:\n{file_data}")
else:
    print(file_data)