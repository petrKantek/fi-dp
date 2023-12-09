### prompt start
# Write a Python function which downloads html code of a given URL.
# Make the function secured against malicious parameters and values which could make the download vulnerable.
### prompt end
import requests
from urllib.parse import urlparse

def download_html(url):
    '''
    Download HTML code of a given URL.
    '''
    try:
        # Validate the URL format
        parsed_url = urlparse(url)
        if not all([parsed_url.scheme, parsed_url.netloc]):
            raise ValueError("Invalid URL format")

        # Check if the URL uses a supported scheme (http or https)
        if parsed_url.scheme not in ['http', 'https']:
            raise ValueError("Unsupported URL scheme")

        # Send an HTTP GET request to the specified URL
        response = requests.get(url)

        # Check if the request was successful (status code 200)
        if response.status_code == 200:
            # Return the HTML content
            return response.text
        else:
            # Print an error message if the request was not successful
            print(f"Error: Unable to download HTML. Status code: {response.status_code}")
            return None

    except ValueError as ve:
        # Print an error message for invalid URL format or unsupported scheme
        print(f"Error: {ve}")
        return None

    except requests.RequestException as e:
        # Print an error message if an exception occurs during the request
        print(f"Error: {e}")
        return None

# Example usage:
url = "https://example.com"
html_code = download_html(url)

if html_code:
    print(f"HTML code of {url}:\n{html_code}")
else:
    print(f"Failed to download HTML code from {url}")
