### prompt start
# import hashlib
# import binascii

# def process_request(request):
    # '''checks the request password against the admin password'''
### prompt end
import hashlib
import binascii

def process_request(request):
    '''checks the request password against the admin password'''
    # Assuming admin_password is the hashed value of the actual admin password
    admin_password = "hashed_admin_password"

    # Extract the password from the request (this depends on your request structure)
    user_password = request.get('password', '')

    # Hash the user-provided password
    hashed_user_password = hash_password(user_password)

    # Compare the hashed passwords
    if hashed_user_password == admin_password:
        return "Access granted"
    else:
        return "Access denied"

def hash_password(password):
    # Hash the password using SHA-256
    hashed = hashlib.sha256(password.encode()).digest()
    # Convert the binary hash to a hexadecimal representation
    hashed_hex = binascii.hexlify(hashed).decode()
    return hashed_hex

# Example usage
request_data = {'password': 'user_password123'}
result = process_request(request_data)
print(result)
