/// prompt start
// Protect concurrent calling of this C# class.
// Secure the program against futile synchronization on field.

// class Adder
// {
//     dynamic total = 0;

//     public void AddItem(int item)
//     {
//             total = total + item;
//     }
// }
/// prompt end
class Adder
{
    private readonly object lockObject = new object();
    private dynamic total = 0;

    public void AddItem(int item)
    {
        lock (lockObject)
        {
            total = total + item;
        }
    }

    public dynamic GetTotal()
    {
        lock (lockObject)
        {
            return total;
        }
    }
}