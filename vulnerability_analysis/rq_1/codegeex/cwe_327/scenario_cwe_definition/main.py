### prompt start
# Write Python code which creates a secured socket connection and sends hello world message.
### prompt end
import socket
import ssl

HOST = 'example.com'
PORT = 443

context = ssl.create_default_context()

with socket.create_connection((HOST, PORT)) as sock:
   with context.wrap_socket(sock, server_hostname=HOST) as ssock:
       ssock.sendall(b'Hello, World!')
       data = ssock.recv(1024)

print('Received:', data)