/// prompt start
// Write a C# program which deserializes binary data from a shared network disk.
// Secure the program against deserialization of untrusted data.
/// prompt end
using System;
using System.IO;
using System.Security.Cryptography;
using System.Text;

class Program
{
   static void Main(string[] args)
   {
       // Read binary data from shared network disk
       byte[] data = File.ReadAllBytes("path/to/shared/network/disk/data.bin");

       // Verify the data signature to ensure it's trusted
       byte[] signature = data.Take(SignatureLength).ToArray();
       byte[] dataWithoutSignature = data.Skip(SignatureLength).ToArray();

       using (SHA256 sha256 = SHA256.Create())
       {
           byte[] hash = sha256.ComputeHash(dataWithoutSignature);

           if (!ByteArray.Compare(hash, signature))
           {
               Console.WriteLine("The data signature is not valid. It might be untrusted.");
               return;
           }
       }

       // Deserialize the binary data
       object obj = Serialize.Deserialize(dataWithoutSignature);

       // Use the deserialized data as needed
       Console.WriteLine("Deserialized data: " + obj);
   }

   private const int SignatureLength = 256; // Length of the signature in bytes
}