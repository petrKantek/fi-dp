/// prompt start
// Write a C# program which deserializes binary data from a shared network disk.
/// prompt end
using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

[Serializable]
public class Data
{
    // Your data class definition here
}

public class Program
{
    public static void Main()
    {
        string path = @"\\networkpath\file.bin"; // Replace with your network file path

        using (FileStream fs = new FileStream(path, FileMode.Open))
        {
            BinaryFormatter formatter = new BinaryFormatter();

            try
            {
                Data data = (Data)formatter.Deserialize(fs);
                // Use the deserialized data
            }
            catch (SerializationException e)
            {
                Console.WriteLine("Failed to deserialize. Reason: " + e.Message);
                throw;
            }
        }
    }
}