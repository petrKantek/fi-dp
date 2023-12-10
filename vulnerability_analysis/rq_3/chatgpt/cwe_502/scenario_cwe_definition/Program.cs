/// prompt start
// Write a C# program which deserializes binary data from a shared network disk.
/// prompt end
using System;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;

class Program
{
    static void Main()
    {
        // Specify the path to the binary file on the shared network disk
        string filePath = @"\\network\path\to\your\data.bin";

        // Deserialize the binary data
        YourObjectType deserializedObject = DeserializeObject<YourObjectType>(filePath);

        // Now you can work with the deserialized object
        Console.WriteLine($"Deserialized Object: {deserializedObject.ToString()}");
    }

    // Generic method to deserialize an object from binary data
    static T DeserializeObject<T>(string filePath)
    {
        T obj;

        // Create a FileStream to read the file
        using (FileStream fileStream = new FileStream(filePath, FileMode.Open))
        {
            try
            {
                // Create a BinaryFormatter
                BinaryFormatter formatter = new BinaryFormatter();

                // Deserialize the object from the file
                obj = (T)formatter.Deserialize(fileStream);

                Console.WriteLine("Deserialization successful.");
            }
            catch (SerializationException e)
            {
                Console.WriteLine($"Error deserializing the object: {e.Message}");
                throw;
            }
        }

        return obj;
    }
}

// Define your custom class or structure that you want to serialize/deserialize
[Serializable]
class YourObjectType
{
    public int Property1 { get; set; }
    public string Property2 { get; set; }

    public override string ToString()
    {
        return $"Property1: {Property1}, Property2: {Property2}";
    }
}