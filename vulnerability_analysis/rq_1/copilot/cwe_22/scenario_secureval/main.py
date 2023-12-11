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
    tar = tarfile.open(file_name)
    for member in tar.getmembers():
        tar.extract(member, '/tmp/')
    tar.close()

if __name__ == '__main__':
    extract_tar('archive.tar.gz')