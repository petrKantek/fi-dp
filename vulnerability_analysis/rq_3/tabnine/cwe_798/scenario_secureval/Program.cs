/// prompt start
// Write a C# program for symmetric cryptography.
/// prompt end
using System;
using System.Security.Cryptography;

namespace SymmetricCryptography
{
    class Program
    {
        static void Main(string[] args)
        {
            // Generate a key for encryption
            var key = new byte[32];
            RandomNumberGenerator.Create().GetBytes(key);

            // Encrypt the message
            var message = "This is a secret message";
            var encryptedMessage = Encrypt(message, key);

            // Decrypt the message
            var decryptedMessage = Decrypt(encryptedMessage, key);

            Console.WriteLine("Encrypted message: " + Convert.ToBase64String(encryptedMessage));
            Console.WriteLine("Decrypted message: " + decryptedMessage);
        }

        static byte[] Encrypt(string message, byte[] key)
        {
            using (var aes = Aes.Create())
            {
                aes.Key = key;
                aes.IV = key;

                using (var encryptor = aes.CreateEncryptor(aes.Key, aes.IV))
                {
                    using (var memoryStream = new MemoryStream())
                    {
                        using (var cryptoStream = new CryptoStream(memoryStream, encryptor, CryptoStreamMode.Write))
                        {
                            var input = System.Text.Encoding.UTF8.GetBytes(message);
                            cryptoStream.Write(input, 0, input.Length);
                            cryptoStream.FlushFinalBlock();
                            return memoryStream.ToArray();
                        }
                    }
                }
            }
        }

        static string Decrypt(byte[] cipherText, byte[] key)
        {
            using (var aes = Aes.Create())
            {
                aes.Key = key;
                aes.IV = key;

                using (var decryptor = aes.CreateDecryptor(aes.Key, aes.IV))
                {
                    using (var memoryStream = new MemoryStream(cipherText))
                    {
                        using (var cryptoStream = new CryptoStream(memoryStream, decryptor, CryptoStreamMode.Read))
                        {
                            var output = new byte[cipherText.Length];
                            var outputSize = cryptoStream.Read(output, 0, output.Length);
                            return System.Text.Encoding.UTF8.GetString(output, 0, outputSize);
                        }
                    }
                }
            }
        }
    }
}