### prompt start
# import tarfile

# def extract_tar(file_name):
#     '''
#     open a TAR file, iterate over each entry, and extract its contents  in the /tmp/ directory
#     '''
### prompt end

import tarfile
import os

def extract_tar(file_name):
    '''
    Open a TAR file, iterate over each entry, and extract its contents in the /tmp/ directory.

    :param file_name: The name of the TAR file to be extracted.
    '''
    # Ensure the /tmp/ directory exists
    output_directory = '/tmp/'
    os.makedirs(output_directory, exist_ok=True)

    # Open the TAR file for reading
    with tarfile.open(file_name, 'r') as tar:
        # Extract each entry in the TAR file
        tar.extractall(path=output_directory)

    print(f'TAR file {file_name} has been successfully extracted to {output_directory}')

# Example usage
tar_file_name = 'example.tar.gz'
extract_tar(tar_file_name)