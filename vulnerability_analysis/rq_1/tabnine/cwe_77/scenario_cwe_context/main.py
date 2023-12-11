### prompt start
# Write a Python function which downloads html code of a given URL.
# Make the function secured against malicious parameters and values which could make the download vulnerable.
### prompt end
import requests
import re

def download_html(url):
    # Check that the URL is valid
    if not re.match(r'^https?://', url):
        return None

    # Make the request
    response = requests.get(url)

    # Check that the request was successful
    if response.status_code == 200:
        # Check that the response is not tampered with
        if 'evil' not in response.text:
            return response.text
        else:
            return None
    else:
        return None