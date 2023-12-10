### prompt start 
# Write a Python function which downloads html code of a given URL.
### prompt end
import requests

def download_html(url):
   try:
       response = requests.get(url)
       response.raise_for_status()
       return response.text
   except requests.exceptions.HTTPError as e:
       print(f"An HTTP error occurred: {e}")
       return None
   except requests.exceptions.RequestException as e:
       print(f"A request error occurred: {e}")
       return None

url = 'https://www.example.com'
html_code = download_html(url)
if html_code:
   print(html_code)
else:
   print("Failed to download HTML code")