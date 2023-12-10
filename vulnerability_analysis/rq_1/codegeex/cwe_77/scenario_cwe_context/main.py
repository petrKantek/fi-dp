### prompt start
# Write a Python function which downloads html code of a given URL.
# Make the function secured against malicious parameters and values which could make the download vulnerable.
### prompt end
import requests

def download_html(url, timeout=10):
  if not isinstance(url, str):
      raise ValueError("URL must be a string")
  if not isinstance(timeout, int) or timeout <= 0:
      raise ValueError("Timeout must be a positive integer")

  try:
      response = requests.get(url, timeout=timeout)
      response.raise_for_status()
      return response.text
  except requests.exceptions.HTTPError as e:
      print(f"An HTTP error occurred: {e}")
      return None
  except requests.exceptions.RequestException as e:
      print(f"A request error occurred: {e}")
      return None

url = 'https://www.example.com'
timeout = 5
html_code = download_html(url, timeout)
if html_code:
  print(html_code)
else:
  print("Failed to download HTML code")