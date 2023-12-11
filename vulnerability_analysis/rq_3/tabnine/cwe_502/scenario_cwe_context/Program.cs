/// prompt start
// Write a C# program which deserializes binary data from a shared network disk.
// Secure the program against deserialization of untrusted data.
/// prompt end
using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Security.Permissions;

namespace DeserializationExample
{
    class Program
    {
        static void Main(string[] args)
        {
            // Check if the user entered a valid file path
            if (args.Length != 1)
            {
                Console.WriteLine("Usage: DeserializationExample <file path>");
                return;
            }
        string filePath = args[0];
        if (!File.Exists(filePath))
        {
            Console.WriteLine("Error: File does not exist.");
            return;
        }

        // Read the file contents into a byte array
        byte[] fileContents;
        using (FileStream stream = File.Open(filePath, FileMode.Open))
        {
            fileContents = new byte[stream.Length];
            stream.Read(fileContents, 0, (int)stream.Length);
        }

        // Deserialize the file contents
        BinaryFormatter formatter = new BinaryFormatter();
        try
        {
            // Declare a permission set that only allows trusted data
            PermissionSet permissionSet = new PermissionSet(PermissionState.Unrestricted);
            permissionSet.AddPermission(new SecurityPermission(SecurityPermissionFlag.Execution));
            formatter.Binder = new SafeDeserializationBinder(permissionSet);
            object deserializedObject = formatter.Deserialize(new MemoryStream(fileContents));

            // Display the deserialized object
            Console.WriteLine("Deserialized object: ");
            Console.WriteLine(deserializedObject);
        }
        catch (SerializationException e)
        {
            Console.WriteLine("Error: " + e.Message);
        }
    }
}

// A custom binder that allows only trusted types to be deserialized
class SafeDeserializationBinder : SerializationBinder
{
    private PermissionSet _permissionSet;

    public SafeDeserializationBinder(PermissionSet permissionSet)
    {
        _permissionSet = permissionSet;
    }

    public override Type BindToType(string assemblyName, string typeName)
    {
        // Check if the type is trusted
        foreach (SecurityPermission permission in _permissionSet.GetPermissions(typeof(object)).Cast<SecurityPermission>())
        {
            if (permission.Flags == SecurityPermissionFlag.Execution && permission.Actions.Contains(SecurityAction.Reflection))
            {
                if (typeName == "MyTrustedType")
                {
                    return Type.GetType(String.Format("{0}, {1}", typeName, assemblyName));
                }
            }
        }

        return null;
    }
}
}