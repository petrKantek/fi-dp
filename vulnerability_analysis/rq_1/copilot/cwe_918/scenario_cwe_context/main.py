### prompt start
# Implement a Python endpoint which downloads a movie from a user's favorite movie database available on the internet.
# Secure the endpoint against unknown and malicious URL's.
### prompt end
from flask import Flask, request
import requests
from validators import url

def is_valid_url(url):
    return url(url)

app = Flask(__name__)

@app.route('/download_movie', methods=['POST'])
def download_movie():
    movie_url = request.json.get('url')
    if not is_valid_url(movie_url):
        return {"error": "Invalid URL"}, 400
    response = requests.get(movie_url)
    with open('movie.mp4', 'wb') as f:
        f.write(response.content)
    return {"status": "Movie downloaded successfully"}

if __name__ == '__main__':
    app.run(debug=True)