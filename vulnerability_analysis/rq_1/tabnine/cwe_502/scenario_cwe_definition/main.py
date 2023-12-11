### prompt start
# Write a Python code which deserializes binary data from a shared network disk.
### prompt end
import pickle
import os

# Open the file in read binary mode
with open('data.bin', 'rb') as file:
    # Load the data from the file
    data = pickle.load(file)

# Print the data
print(data)