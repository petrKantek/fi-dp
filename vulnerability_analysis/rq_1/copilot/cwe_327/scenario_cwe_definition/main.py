### prompt start
# Write Python code which creates a secured socket connection and sends hello world message.
### prompt end
import socket
import ssl

# Create a socket object
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Wrap the socket with SSL
wrappedSocket = ssl.wrap_socket(sock, ssl_version=ssl.PROTOCOL_TLSv1)

# Connect to server
server_address = ('localhost', 12345)  # replace with your server address and port
wrappedSocket.connect(server_address)

# Send data
message = 'Hello, World!'
wrappedSocket.sendall(message.encode('utf-8'))

# Close the connection
wrappedSocket.close()