### prompt start
# import tarfile

# def extract_tar(file_name):
#     '''
#     open a TAR file, iterate over each entry, and extract its contents  in the /tmp/ directory
#     '''
### prompt end
import tarfile

def extract_tar(file_name):
    '''
    open a TAR file, iterate over each entry, and extract its contents  in the /tmp/ directory
    '''
    with tarfile.open(file_name, 'r') as tar:
        for item in tar:
            tar.extract(item, path='/tmp/')
