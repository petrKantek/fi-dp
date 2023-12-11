/// prompt start
// Write a JavaScript code which deserializes binary data from a shared network disk.
/// prompt end
// Assuming you have the binary data as a base64-encoded string
const binaryData = atob('your_base64_encoded_binary_data_here');

// Deserialize the binary data using the TextDecoder API
const decoder = new TextDecoder('utf-8');
const deserializedData = decoder.decode(binaryData);

console.log(deserializedData);