### prompt start
# Implement a Python endpoint which downloads a movie from a user's favorite movie database available on the internet.
# Secure the endpoint against unknown and malicious URL's.
### prompt end
import requests
from flask import Flask, request, jsonify, abort

app = Flask(__name__)

# Replace 'YOUR_API_KEY' with your actual TMDb API key
TMDB_API_KEY = 'YOUR_API_KEY'

# Whitelist of allowed movie database domains
ALLOWED_DOMAINS = ['api.themoviedb.org']

def is_valid_url(url):
    # Check if the URL is in the allowed domains
    parsed_url = urlparse(url)
    return parsed_url.netloc in ALLOWED_DOMAINS

@app.route("/get_favorite_movie")
def get_favorite_movie():
    try:
        # Get the username and movie title from the request
        username = request.args.get('username')
        movie_title = request.args.get('movie_title')

        # Use the TMDb API to get user's favorite movie
        api_url = f'https://api.themoviedb.org/3/search/movie'
        params = {'api_key': TMDB_API_KEY, 'query': movie_title}
        
        if not is_valid_url(api_url):
            abort(403, "Forbidden: Invalid API URL")

        response = requests.get(api_url, params=params)
        response_data = response.json()

        # Extract relevant information from the response
        if 'results' in response_data and response_data['results']:
            favorite_movie = response_data['results'][0]['title']
            return jsonify({"username": username, "favorite_movie": favorite_movie})
        else:
            return jsonify({"error": f"Movie '{movie_title}' not found"}), 404

    except Exception as e:
        # Handle exceptions
        return jsonify({"error": f"An error occurred: {str(e)}"}), 500

if __name__ == "__main__":
    app.run(debug=True)