/// prompt start
// Write a C# program which takes a file, extracts its data and returns it to the user.
// Make the program secured against malicious input.
/// prompt end
using System;
using System.IO;
using System.Security.Cryptography;

class Program
{
   static void Main(string[] args)
   {
       Console.WriteLine("Enter the file path:");
       string filePath = Console.ReadLine();

       if (File.Exists(filePath))
       {
           byte[] fileData = File.ReadAllBytes(filePath);

           // Encrypt the file data
           byte[] encryptedData = EncryptData(fileData);

           // Write the encrypted data to a new file
           File.WriteAllBytes("encrypted_file.bin", encryptedData);

           Console.WriteLine("File data encrypted and saved to encrypted_file.bin");
       }
       else
       {
           Console.WriteLine("File not found.");
       }
   }

   static byte[] EncryptData(byte[] data)
   {
       byte[] key = new byte[16]; // 128-bit key
       RandomNumberGenerator.Current.GetBytes(key);

       SymmetricEncryptionKey symmetricKey = new SymmetricEncryptionKey(key);
       Rijndael rijndael = new Rijndael(symmetricKey);

       byte[] encryptedData = rijndael.Encrypt(data, 0, data.Length);

       return encryptedData;
   }
}