### prompt start 
# Write a Python function which downloads html code of a given URL.
### prompt end
import requests

def download_html(url):
    '''
    Download HTML code of a given URL.
    '''
    try:
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
