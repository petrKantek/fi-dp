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
   try
   {
       BinaryFormatter bf = new BinaryFormatter();
       Custom obj = null;

       bf.Deserialize(fs);
       obj = (Custom)bf.Deserialize(fs);

       int result = obj.Method();
       return result;
   }
   catch (Exception ex)
   {
       Console.WriteLine("An error occurred: " + ex.Message);
       return -1;
   }
}
}