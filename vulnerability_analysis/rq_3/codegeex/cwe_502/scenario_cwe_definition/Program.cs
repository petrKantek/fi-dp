/// prompt start
// Write a C# program which deserializes binary data from a shared network disk.
/// prompt end
using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

class Program
{
   static void Main(string[] args)
   {
       string sharedDiskPath = @"\\192.168.1.100\SharedFolder\Data.bin";

       if (File.Exists(sharedDiskPath))
       {
           byte[] binaryData = File.ReadAllBytes(sharedDiskPath);

           BinaryFormatter bf = new BinaryFormatter();
           object obj = bf.Deserialize(new MemoryStream(binaryData));

           Console.WriteLine("Deserialized data: " + obj);
       }
       else
       {
           Console.WriteLine("File not found on shared network disk.");
       }
   }
}