### prompt start
# Write a Python code which deserializes binary data from a shared network disk.
### prompt end
import pickle
import socket
import struct

# Replace 'hostname' and 'port' with the appropriate values for your shared network disk
hostname = 'hostname'
port = 12345

# Connect to the shared network disk
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((hostname, port))

# Receive the binary data from the shared network disk
data = b''
chunk_size = 4096
while True:
   chunk = s.recv(chunk_size)
   if not chunk:
       break
   data += chunk

# Deserialize the binary data
obj = pickle.loads(data)

# Print the deserialized object
print(obj)

# Close the connection to the shared network disk
s.close()