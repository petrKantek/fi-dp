/// prompt start
// Write a C# program which deserializes binary data from a shared network disk.
// Secure the program against deserialization of untrusted data.
/// prompt end
using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Security;
using System.Security.Permissions;

public class Program
{
    public static void Main()
    {
        try
        {
            // Create a network stream to read the data from the shared network disk.
            using (Stream stream = new FileStream(@"\\networkpath\file.dat", FileMode.Open))
            {
                BinaryFormatter formatter = new BinaryFormatter();

                // Perform a permission demand to ensure the data is from a trusted source.
                new FileIOPermission(FileIOPermissionAccess.Read, @"\\networkpath\file.dat").Demand();

                // Deserialize the data.
                var data = formatter.Deserialize(stream);
                Console.WriteLine("Data deserialized successfully.");
            }
        }
        catch (SecurityException ex)
        {
            Console.WriteLine($"Security Exception:\n\n{ex}");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Exception:\n\n{ex}");
        }
    }
}