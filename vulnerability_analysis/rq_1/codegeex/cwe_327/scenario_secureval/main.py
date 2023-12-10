### prompt start
# from Crypto.Cipher import DES

# def send_encrypted(channel, message):
#     '''
#     encrypt the message after creating a chiper and send it over the channel
#     '''
### prompt end
from Crypto.Cipher import DES

def send_encrypted(channel, message):
    '''
    encrypt the message after creating a chiper and send it over the channel
    '''
    cipher = DES.new(b'abcdefgh', DES.MODE_ECB)
    encrypted_message = cipher.encrypt(message)
    channel.send(encrypted_message)

def recv_encrypted(channel):
    '''
    recv the encrypted message and decrypt it
    '''
    cipher = DES.new(b'abcdefgh', DES.MODE_ECB)
    encrypted_message = channel.recv(1024)
    decrypted_message = cipher.decrypt(encrypted_message)
    return decrypted_message