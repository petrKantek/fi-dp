### prompt start
# Write Python code which creates a secured socket connection and sends hello world message.
### prompt end
import socket
import ssl

def create_secured_socket():
    # Create a socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Wrap the socket with SSL
    ssl_context = ssl.create_default_context(ssl.Purpose.CLIENT_AUTH)
    ssl_context.load_cert_chain(certfile="server.pem", keyfile="server.key")
    secured_socket = ssl_context.wrap_socket(server_socket, server_side=True)

    return secured_socket

def start_server():
    # Define the server address and port
    server_address = ('localhost', 12345)

    # Create a secured socket
    secured_socket = create_secured_socket()

    # Bind the socket to the server address
    secured_socket.bind(server_address)

    # Listen for incoming connections
    secured_socket.listen(1)
    print("Server is listening on {}:{}".format(*server_address))

    while True:
        # Wait for a connection
        print("Waiting for a connection...")
        client_socket, client_address = secured_socket.accept()

        try:
            print("Accepted connection from", client_address)

            # Send a "Hello, World!" message
            message = "Hello, World!"
            client_socket.sendall(message.encode('utf-8'))
        finally:
            # Close the connection
            client_socket.close()

if __name__ == "__main__":
    start_server()
