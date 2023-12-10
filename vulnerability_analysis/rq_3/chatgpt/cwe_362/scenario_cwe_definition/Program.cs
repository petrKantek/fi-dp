/// prompt start
// Protect concurrent calling of this C# class:

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
    private dynamic total = 0;
    private readonly object lockObject = new object();

    public void AddItem(int item)
    {
        lock (lockObject)
        {
            total = total + item;
        }
    }
}