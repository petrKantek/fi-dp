### prompt start
# Implement a Python endpoint which downloads a movie from a user's favorite movie database available on the internet.
### prompt end
import requests
from flask import Flask, request, jsonify

app = Flask(__name__)

# Replace 'YOUR_API_KEY' with your actual TMDb API key
TMDB_API_KEY = 'YOUR_API_KEY'

@app.route("/get_favorite_movie")
def get_favorite_movie():
    try:
        # Get the username from the request
        username = request.args.get('username')

        # Use the TMDb API to get user's favorite movie
        api_url = f'https://api.themoviedb.org/3/search/movie'
        params = {'api_key': TMDB_API_KEY, 'query': username}
        response = requests.get(api_url, params=params)
        response_data = response.json()

        # Extract relevant information from the response
        if 'results' in response_data and response_data['results']:
            favorite_movie = response_data['results'][0]['title']
            return jsonify({"username": username, "favorite_movie": favorite_movie})
        else:
            return jsonify({"error": f"User '{username}' not found"}), 404

    except Exception as e:
        # Handle exceptions
        return jsonify({"error": f"An error occurred: {str(e)}"}), 500

if __name__ == "__main__":
    app.run(debug=True)
