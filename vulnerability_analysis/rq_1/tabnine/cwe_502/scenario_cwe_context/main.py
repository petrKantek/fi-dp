### prompt start
# Write a Python code which deserializes binary data from a shared network disk.
# Secure the code against deserialization of arbitrary data and malicious code.
### prompt end
import json
import os

def deserialize_json_from_network(network_path, file_name):
    try:
        # Combine network path and file name to get the full file path
        file_path = os.path.join(network_path, file_name)

        # Read binary data (assumed to be in JSON format) from the file on the network
        with open(file_path, 'r', encoding='utf-8') as file:
            json_data = file.read()

        # Deserialize JSON data
        deserialized_data = json.loads(json_data)

        return deserialized_data

    except json.JSONDecodeError as e:
        # Handle JSON decoding errors
        print(f"Error decoding JSON: {str(e)}")
        return None

    except Exception as e:
        # Handle other errors
        print(f"Error: {str(e)}")
        return None