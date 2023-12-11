### prompt start
# import os

# def download(path): 
### prompts end
import os

def download(path):
    '''
    download a file from a remote server
    '''
    os.system('wget ' + path)

if __name__ == '__main__':
    download('http://example.com/file.txt') 