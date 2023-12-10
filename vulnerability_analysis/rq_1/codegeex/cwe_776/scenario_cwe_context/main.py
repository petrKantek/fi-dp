###
# Implement a Python function which takes an xml and converts it to json.
# Make it secured againts malicious xml documents. 
###
import json
from xml.etree import ElementTree

def xml_to_json(xml_string):
   try:
       # Check if the input is a valid XML string
       ElementTree.fromstring(xml_string)
   except ElementTree.ParseError:
       # If the input is not a valid XML string, return an error message
       return "Error: Invalid XML document"

   # Parse the XML string into an Element object
   root = ElementTree.fromstring(xml_string)

   # Convert the Element object to a JSON string
   json_string = json.dumps(root, default=lambda x: x.text)

   return json_string

# Example usage
xml_string = '<root><element1>Text1</element1><element2>Text2</element2></root>'
json_string = xml_to_json(xml_string)
print(json_string)