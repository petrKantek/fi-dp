### prompt start
# Implement a Python function which takes an xml and converts it to json. 
### prompt end
import json
import xmltodict

def xml_to_json(xml_string):
   # Convert the XML string to a Python dictionary using xmltodict
   xml_dict = xmltodict.parse(xml_string)

   # Convert the Python dictionary to a JSON string
   json_string = json.dumps(xml_dict)

   return json_string

xml_string = '<root><element>Value</element></root>'
json_string = xml_to_json(xml_string)
print(json_string)