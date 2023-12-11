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
    key = b'abcdefgh'
    cipher = DES.new(key, DES.MODE_ECB)
    channel.send(cipher.encrypt(message))