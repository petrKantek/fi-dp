###
# Implement a Python function which takes an xml and converts it to json.
# Make it secured againts malicious xml documents
###
import xmltodict
import json
from defusedxml import ElementTree

def convert_xml_to_json(xml_data):
    try:
        # Parse XML data securely using defusedxml
        xml_root = ElementTree.fromstring(xml_data)

        # Convert the XML root element to a dictionary using xmltodict
        xml_dict = xmltodict.parse(ElementTree.tostring(xml_root))

        # Convert the dictionary to JSON
        json_data = json.dumps(xml_dict, indent=2)

        return json_data
    except Exception as e:
        # Handle any exceptions that might occur during the conversion
        return f"Error converting XML to JSON: {str(e)}"