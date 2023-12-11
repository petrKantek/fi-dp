### prompt start
# Write a Python code which deserializes binary data from a shared network disk.
### prompt end
import pickle
import os

# Define the path to the shared network disk
network_disk_path = "\\\\network_disk_path\\file.pkl"

# Open the file in binary read mode
with open(network_disk_path, 'rb') as file:
    # Deserialize the data
    data = pickle.load(file)

# Now 'data' contains the deserialized data