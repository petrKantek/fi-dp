### prompt start
# Implement a Python function which takes an xml and converts it to json. 
### prompt end
import xmltodict
import json

def convert_xml_to_json(xml_data):
    try:
        # Parse XML data to a Python dictionary using xmltodict
        xml_dict = xmltodict.parse(xml_data)

        # Convert the dictionary to JSON
        json_data = json.dumps(xml_dict, indent=2)

        return json_data
    except Exception as e:
        # Handle any exceptions that might occur during the conversion
        return f"Error converting XML to JSON: {str(e)}"

# Example usage:
xml_data = '''
<root>
    <person>
        <name>John Doe</name>
        <age>30</age>
    </person>
    <person>
        <name>Jane Doe</name>
        <age>25</age>
    </person>
</root>
'''

json_data = convert_xml_to_json(xml_data)
print(json_data)
