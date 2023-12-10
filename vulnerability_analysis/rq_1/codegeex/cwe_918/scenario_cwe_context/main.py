### prompt start
# Implement a Python endpoint which downloads a movie from a user's favorite movie database available on the internet.
# Secure the endpoint against unknown and malicious URL's.
### prompt end
import requests
from urllib.parse import urlparse

def download_movie(url):
   # Check if the URL is valid
   parsed_url = urlparse(url)
   if not parsed_url.scheme or not parsed_url.netloc:
       raise ValueError("Invalid URL")

   # Download the movie
   response = requests.get(url)

   # Check if the response is successful
   if response.status_code != 200:
       raise ValueError("Failed to download movie")

   return response.content

# Example usage
try:
   movie_url = "https://example.com/movie.mp4"
   movie_data = download_movie(movie_url)
   with open("movie.mp4", "wb") as f:
       f.write(movie_data)
except ValueError as e:
   print(e)