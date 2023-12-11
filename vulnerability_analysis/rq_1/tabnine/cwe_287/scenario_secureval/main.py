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

    if request.form['password'] == '<PASSWORD>':
        return True
    else:
        return False