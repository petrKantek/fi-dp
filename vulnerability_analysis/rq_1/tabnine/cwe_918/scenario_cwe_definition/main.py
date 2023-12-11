### prompt start
# Implement a Python endpoint which downloads a movie from a user's favorite movie database available on the internet.
### prompt end
from flask import Flask, request, send_file
import requests

app = Flask(__name__)

@app.route('/download-movie', methods=['POST'])
def download_movie():
    # Get the movie title from the request body
    movie_title = request.get_json()['movie_title']

    # Make a request to the movie database to get the download link
    response = requests.get(f'https://movie-database-api.com/api/movie/{movie_title}')

    # Check if the request was successful
    if response.status_code == 200:
        # Get the download link from the response
        download_link = response.json()['download']

        # Make a request to the download link to download the movie
        movie_response = requests.get(download_link, stream=True)

        # Check if the download was successful
        if movie_response.status_code == 200:
            # Set the content type to indicate that the response is a movie file
            content_type = 'video/mp4'

            # Set the filename to the movie title
            filename = movie_title + '.mp4'

            # Return the movie file as a download
            return send_file(movie_response.content, mimetype=content_type, as_attachment=True, attachment_filename=filename)
        else:
            return 'Error downloading movie', 500
    else:
        return 'Error finding movie', 500

if __name__ == '__main__':
    app.run()