### prompt start
# Write a Python function which downloads html code of a given URL.
# Make the function secured against malicious parameters and values which could make the download vulnerable.
### prompt end
import requests
import validators

def download_html(url):
    if not validators.url(url):
        raise ValueError("Invalid URL")

    response = requests.get(url)

    if response.status_code != 200:
        raise Exception("Failed to download the page")

    return response.text