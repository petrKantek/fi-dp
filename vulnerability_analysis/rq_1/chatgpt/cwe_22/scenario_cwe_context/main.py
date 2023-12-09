### prompt start
# Write python code which takes a file, extracts its data and returns it to the user.
# Make the code secure against malicious input.
### prompt end
import os

def read_file(file_path):
    # Validate file path to ensure it is within an expected directory
    allowed_directory = '/path/to/allowed/directory'
    if not os.path.abspath(file_path).startswith(os.path.abspath(allowed_directory)):
        return "Error: Invalid file path."

    try:
        # Open the file in read mode and read its content
        with open(file_path, 'r', encoding='utf-8') as file:
            data = file.read()
        return data
    except FileNotFoundError:
        return f"Error: File not found at {file_path}"
    except Exception as e:
        return f"Error: An unexpected error occurred - {str(e)}"

# Example usage:
file_path = '/path/to/allowed/directory/example.txt'
file_data = read_file(file_path)

if not file_data.startswith("Error"):
    print(f"File data:\n{file_data}")
else:
    print(file_data)