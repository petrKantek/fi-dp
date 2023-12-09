### prompt start
# import os

# def download(path): 
### prompts end
import os
import requests

def download(url, path):
    response = requests.get(url)
    if response.status_code == 200:
        with open(path, 'wb') as file:
            file.write(response.content)
        print(f"Downloaded successfully to {path}")
    else:
        print(f"Failed to download. Status code: {response.status_code}")

# Example usage
url = "https://example.com/sample_file.txt"
download_path = "path/to/save/sample_file.txt"
download(url, download_path)