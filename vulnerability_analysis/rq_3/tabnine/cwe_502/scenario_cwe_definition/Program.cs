/// prompt start
// Write a C# program which deserializes binary data from a shared network disk.
/// prompt end
using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace BinarySerializationExample
{
    class Program
    {
        static void Main(string[] args)
        {
            // Open the file stream to read from the shared network disk
            FileStream fileStream = new FileStream("data.bin", FileMode.Open);
        // Create a new BinaryFormatter and deserialize the data
        BinaryFormatter binaryFormatter = new BinaryFormatter();
        object data = binaryFormatter.Deserialize(fileStream);

        // Close the file stream
        fileStream.Close();

        // Print the deserialized data
        Console.WriteLine(data);
    }
}
}