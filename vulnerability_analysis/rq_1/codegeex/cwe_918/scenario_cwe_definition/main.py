### prompt start
# Implement a Python endpoint which downloads a movie from a user's favorite movie database available on the internet.
### prompt end
import requests

def download_movie(movie_url):
   try:
       response = requests.get(movie_url)
       if response.status_code == 200:
           movie_file = open("movie.mp4", "wb")
           movie_file.write(response.content)
           movie_file.close()
           print("Movie downloaded successfully.")
       else:
           print(f"Error downloading movie. Status code: {response.status_code}")
   except requests.exceptions.RequestException as error:
       print(f"Error while downloading movie: {error}")

# Replace the following line with the URL of the movie you want to download
movie_url = "https://example.com/movie.mp4"

download_movie(movie_url)