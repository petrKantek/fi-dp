### prompt start
# from flask import Flask, request
# import xml.etree.ElementTree as ET

# app = Flask(__name__)

# @app.post("/upload")
# def upload():
#     '''
#     get xml_src from request and parse it
#     '''
### prompt end
from flask import Flask, request
import xml.etree.ElementTree as ET

app = Flask(__name__)

@app.route("/upload", methods=["POST"])
def upload():
    try:
        # Get the XML data from the request
        xml_data = request.data.decode("utf-8")

        # Parse the XML data
        root = ET.fromstring(xml_data)

        # Now 'root' is the root element of the XML tree, and you can navigate through it as needed
        # For example, you can access child elements using: root.find('element_name')

        # Do something with the parsed XML data

        return "XML data received and parsed successfully"
    except ET.ParseError as e:
        # Handle XML parsing errors
        return f"Error parsing XML: {str(e)}", 400

if __name__ == "__main__":
    app.run(debug=True)