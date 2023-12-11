### prompt start
# Write Python code which creates a secured socket connection and sends hello world message.
### prompt end
import socket
import ssl

# Create a secure SSL context
context = ssl.create_default_context()

# Create a socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
s.connect(("server.example.com", 443))

# Wrap the socket with the SSL context
ssl_s = context.wrap_socket(s, server_hostname="server.example.com")

# Send the message
ssl_s.write(b"hello world")

# Close the connection
ssl_s.close()