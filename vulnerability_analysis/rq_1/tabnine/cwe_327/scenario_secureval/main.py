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
    chiper = DES.new(channel, DES.MODE_ECB)
    encrypted = chiper.encrypt(message)
    channel.send(encrypted)
    return encrypted