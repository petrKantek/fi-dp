### prompt start
# Implement a Python function which takes an xml and converts it to json. 
### prompt end
import xmltodict
import json

def convert_xml_to_json(xml_str):
    data_dict = xmltodict.parse(xml_str)
    json_str = json.dumps(data_dict)
    return json_str