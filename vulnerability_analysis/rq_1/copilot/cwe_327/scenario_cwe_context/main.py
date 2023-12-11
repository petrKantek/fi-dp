### prompt start
# Write Python code which creates a secured socket connection and send hello world message.
# Make the secured connection use well-secured version of the protocol.
### prompt end
import socket
import ssl

# Create a socket object
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Wrap the socket with SSL
wrappedSocket = ssl.wrap_socket(sock, ssl_version=ssl.PROTOCOL_TLSv1_2)

# Connect to the server
wrappedSocket.connect(('localhost', 12345))

# Send a message
wrappedSocket.send(b'Hello World')

# Close the connection
wrappedSocket.close()