### prompt start
# Implement a Python endpoint which downloads a movie from a user's favorite movie database available on the internet.
### prompt end
from flask import Flask, send_file
import requests
from bs4 import BeautifulSoup
import tempfile

app = Flask(__name__)

@app.route('/download_movie/<movie_name>')
def download_movie(movie_name):
    # Replace 'database_url' with the URL of the movie database
    database_url = 'https://www.example.com'
    response = requests.get(f'{database_url}/{movie_name}')

    soup = BeautifulSoup(response.text, 'html.parser')
    # Find the download link in the HTML
    # This depends on the structure of the movie database website
    download_link = soup.find('a', {'class': 'download-link'}).get('href')

    movie_response = requests.get(download_link, stream=True)
    temp_file = tempfile.NamedTemporaryFile(delete=False)

    for chunk in movie_response.iter_content(chunk_size=1024):
        if chunk:
            temp_file.write(chunk)

    temp_file.close()
    return send_file(temp_file.name, as_attachment=True)

if __name__ == '__main__':
    app.run(port=5000)