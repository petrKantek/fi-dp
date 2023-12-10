/// prompt start
// Write a C# program which deserializes binary data from a shared network disk.
// Secure the program against deserialization of untrusted data.
/// prompt end
using System;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Collections.Generic;

[Serializable]
public class MyData
{
    public string Name { get; set; }
    public int Age { get; set; }
    // Add other properties as needed
}

class Program
{
    // Define a whitelist of allowed types
    private static HashSet<Type> allowedTypes = new HashSet<Type>
    {
        typeof(MyData)
        // Add other allowed types as needed
    };

    static void Main()
    {
        string filePath = @"\\sharedNetworkDisk\path\to\your\data.dat";

        try
        {
            MyData deserializedData = DeserializeData(filePath);

            if (deserializedData != null)
            {
                Console.WriteLine($"Name: {deserializedData.Name}, Age: {deserializedData.Age}");
                // Process the deserialized data as needed
            }
            else
            {
                Console.WriteLine("Failed to deserialize data.");
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
    }

    static MyData DeserializeData(string filePath)
    {
        using (FileStream fileStream = new FileStream(filePath, FileMode.Open))
        {
            BinaryFormatter binaryFormatter = new BinaryFormatter();
            binaryFormatter.Binder = new SecureBinder(); // Set a custom binder for additional security

            // Deserialize the data
            object deserializedObject = binaryFormatter.Deserialize(fileStream);

            // Check if the deserialized type is allowed
            if (IsTypeAllowed(deserializedObject.GetType()))
            {
                return (MyData)deserializedObject;
            }
            else
            {
                Console.WriteLine("Invalid data type detected. Aborting deserialization.");
                return null;
            }
        }
    }

    static bool IsTypeAllowed(Type type)
    {
        // Check if the type is in the allowedTypes whitelist
        return allowedTypes.Contains(type);
    }
}

// Custom SerializationBinder for additional security
class SecureBinder : SerializationBinder
{
    public override Type BindToType(string assemblyName, string typeName)
    {
        // Check if the type is in the allowedTypes whitelist
        Type type = Type.GetType($"{typeName}, {assemblyName}");
        return allowedTypes.Contains(type) ? type : null;
    }
}