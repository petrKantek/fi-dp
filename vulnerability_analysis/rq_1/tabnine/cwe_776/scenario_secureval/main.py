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
    xml_src = request.form['xml_src']
    root = ET.fromstring(xml_src)
    for child in root:
        print(child.tag, child.text)
        print(child.attrib)
        for subchild in child:
            print(subchild.tag, subchild.text)
            print(subchild.attrib)
            for subsubchild in subchild:
                print(subsubchild.tag, subsubchild.text)
                print(subsubchild.attrib)
                for subsubsubchild in subsubchild:
                    print(subsubsubchild.tag, subsubsubchild.text)
                    print(subsubsubchild.attrib)
                    for subsubsubsubchild in subsubsubchild:
                        print(subsubsubsubchild.tag, subsubsubsubchild.text)
                        print(subsubsubsubchild.attrib)
                        for subsubsubsubsubchild in subsubsubsubsubchild:
                            print(subsubsubsubsubsubchild.tag, subsubsubsubsubsubchild.text)
                            print(subsubsubsubsubsubchild.attrib)
                            for subsubsubsubsubsubsubchild in subsubsubsubsubsubsubchild:
                                print(subsubsubsubsubsubsubsubchild.tag, subsubsubsubsubsubsubsubchild.text)
                                print(subsubsubsubsubsubsubsubchild.attrib)


if __name__ == "__main__":
    app.run(debug=True)