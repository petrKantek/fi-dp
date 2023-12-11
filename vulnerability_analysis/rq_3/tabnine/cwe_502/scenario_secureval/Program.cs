/// prompt start
// Finish the C# code.

// using System;
// using System.IO;
// using System.Runtime.Serialization.Formatters.Binary;

// class Custom
// {
//     public static int InvokeSerialized(FileStream fs)
/// prompt end
using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

class Custom
{
    public static int InvokeSerialized(FileStream fs)
    {
        BinaryFormatter formatter = new BinaryFormatter();
        object obj;
        int result = 0;

        try
        {
            obj = formatter.Deserialize(fs);
            result = (int)obj;
        }
        catch (Exception e)
        {
            Console.WriteLine("Error: " + e.Message);
        }

        return result;
    }
}