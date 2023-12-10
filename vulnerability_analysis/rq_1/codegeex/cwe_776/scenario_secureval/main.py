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

@app.post("/upload")
def upload():
    '''
    get xml_src from request and parse it
    '''
    xml_src = request.get_data()
    root = ET.fromstring(xml_src)
    print(root)
    return "OK"

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8080)