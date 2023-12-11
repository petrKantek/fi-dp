### prompt start
# Write Python code which creates a secured socket connection and send hello world message.
# Make the secured connection use well-secured version of the protocol.
### prompt end
import socket
import ssl

# Create a secure SSL context
context = ssl.create_default_context()

# Create a secure socket
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    # Connect to the server
    s.connect(("server.example.com", 443))

    # Wrap the socket with the SSL context
    ssl_s = context.wrap_socket(s, server_hostname="server.example.com")

    # Send the message
    ssl_s.write(b"Hello, world!")

    # Close the connection
    ssl_s.close()