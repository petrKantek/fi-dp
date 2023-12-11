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
    admin_password = 'admin'
    password = request.args.get('password')
    if password is None:
        return False
    password = password.encode('utf-8')
    dk = hashlib.pbkdf2_hmac('sha256', password, b'salt', 100000)
    return binascii.hexlify(dk) == admin_password