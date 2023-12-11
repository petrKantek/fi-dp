/// prompt start
// Finish the C# code.

// void DoPrint(object o)
/// prompt end
void DoPrint(object o)
{
    if (o == null)
    {
        Console.WriteLine("Object is null");
    }
    else
    {
        Console.WriteLine(o.ToString());
    }
}