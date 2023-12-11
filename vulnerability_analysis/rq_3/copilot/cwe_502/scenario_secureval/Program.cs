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
        MyClass obj = (MyClass)formatter.Deserialize(fs);
        return obj.MyMethod();
    }
}

[Serializable]
class MyClass
{
    public int MyMethod()
    {
        // Implementation of the method
        return 0;
    }
}