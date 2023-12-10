/// prompt start
// Write a C# program for symmetric cryptography.
/// prompt end
using System;
using System.IO;
using System.Security.Cryptography;
using System.Text;

class SymmetricCryptographyExample
{
    static void Main()
    {
        // Replace these keys with your own secret keys
        string secretKey = "ThisIsASecretKey123";
        string initializationVector = "RandomIV123456789";

        string originalText = "Hello, symmetric cryptography!";
        Console.WriteLine($"Original Text: {originalText}");

        // Encrypt the text
        string encryptedText = Encrypt(originalText, secretKey, initializationVector);
        Console.WriteLine($"Encrypted Text: {encryptedText}");

        // Decrypt the text
        string decryptedText = Decrypt(encryptedText, secretKey, initializationVector);
        Console.WriteLine($"Decrypted Text: {decryptedText}");

        Console.ReadLine();
    }

    static string Encrypt(string plainText, string key, string iv)
    {
        using (AesManaged aesAlg = new AesManaged())
        {
            aesAlg.Key = Encoding.UTF8.GetBytes(key);
            aesAlg.IV = Encoding.UTF8.GetBytes(iv);

            ICryptoTransform encryptor = aesAlg.CreateEncryptor(aesAlg.Key, aesAlg.IV);

            using (MemoryStream msEncrypt = new MemoryStream())
            {
                using (CryptoStream csEncrypt = new CryptoStream(msEncrypt, encryptor, CryptoStreamMode.Write))
                {
                    using (StreamWriter swEncrypt = new StreamWriter(csEncrypt))
                    {
                        swEncrypt.Write(plainText);
                    }
                }

                return Convert.ToBase64String(msEncrypt.ToArray());
            }
        }
    }

    static string Decrypt(string cipherText, string key, string iv)
    {
        using (AesManaged aesAlg = new AesManaged())
        {
            aesAlg.Key = Encoding.UTF8.GetBytes(key);
            aesAlg.IV = Encoding.UTF8.GetBytes(iv);

            ICryptoTransform decryptor = aesAlg.CreateDecryptor(aesAlg.Key, aesAlg.IV);

            using (MemoryStream msDecrypt = new MemoryStream(Convert.FromBase64String(cipherText)))
            {
                using (CryptoStream csDecrypt = new CryptoStream(msDecrypt, decryptor, CryptoStreamMode.Read))
                {
                    using (StreamReader srDecrypt = new StreamReader(csDecrypt))
                    {
                        return srDecrypt.ReadToEnd();
                    }
                }
            }
        }
    }
}