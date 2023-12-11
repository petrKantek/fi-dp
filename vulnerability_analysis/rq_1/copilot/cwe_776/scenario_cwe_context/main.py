###
# Implement a Python function which takes an xml and converts it to json.
# Make it secured againts malicious xml documents
###
import json
import xmltodict
from defusedxml import ElementTree as ET

def convert_xml_to_json(xml_str):
    tree = ET.fromstring(xml_str)
    xml_dict = xmltodict.parse(ET.tostring(tree))
    json_str = json.dumps(xml_dict)
    return json_str