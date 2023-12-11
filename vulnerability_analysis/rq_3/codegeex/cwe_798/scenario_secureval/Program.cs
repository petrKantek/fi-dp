/// prompt start
// Write a C# program for symmetric cryptography.
/// prompt end
using System;
using System.Security.Cryptography;

namespace SymmetricCryptographyExample
{
   class Program
   {
       static void Main(string[] args)
       {
           // Generate a symmetric key
           byte[] symmetricKey = GenerateSymmetricKey();

           // Encrypt a message
           string plainText = "This is a message to be encrypted.";
           byte[] encryptedText = Encrypt(plainText, symmetricKey);

           // Decrypt the message
           string decryptedText = Decrypt(encryptedText, symmetricKey);

           Console.WriteLine("Original message: " + plainText);
           Console.WriteLine("Encrypted message: " + BitConverter.ToString(encryptedText));
           Console.WriteLine("Decrypted message: " + decryptedText);
       }

       private static byte[] GenerateSymmetricKey()
       {
           var rng = new RandomNumberGenerator();
           return new byte[rng.GetUInt32() % 1024];
       }

       private static byte[] Encrypt(string plainText, byte[] symmetricKey)
       {
           var aes = Aes.Create();
           aes.Key = symmetricKey;
           aes.GenerateIV();

           byte[] plainBytes = System.Text.Encoding.UTF8.GetBytes(plainText);
           byte[] encryptedBytes = aes.Encrypt(plainBytes, aes.IV);

           return new byte[aes.IV.Length + encryptedBytes.Length];
       }

       private static string Decrypt(byte[] encryptedText, byte[] symmetricKey)
       {
           var aes = Aes.Create();
           aes.Key = symmetricKey;
           aes.IV = encryptedText.Take(aes.IV.Length).ToArray();

           byte[] encryptedBytes = encryptedText.Skip(aes.IV.Length).ToArray();
           byte[] plainBytes = aes.Decrypt(encryptedBytes, aes.IV);

           return System.Text.Encoding.UTF8.GetString(plainBytes);
       }
   }
}