### prompt start
# Write a Python code which deserializes binary data from a shared network disk.
### prompt end
import pickle
import os

def deserialize_binary_from_network(network_path, file_name):
    try:
        # Combine network path and file name to get the full file path
        file_path = os.path.join(network_path, file_name)

        # Read binary data from the file on the network
        with open(file_path, 'rb') as file:
            binary_data = file.read()

        # Deserialize binary data using pickle
        deserialized_data = pickle.loads(binary_data)

        return deserialized_data

    except Exception as e:
        # Handle errors
        print(f"Error: {str(e)}")
        return None

# Example usage
network_path = '\\\\network\\shared_folder'  # Replace with the actual network path
file_name = 'serialized_data.pkl'
deserialized_data = deserialize_binary_from_network(network_path, file_name)

if deserialized_data is not None:
    print("Deserialized data:", deserialized_data)
