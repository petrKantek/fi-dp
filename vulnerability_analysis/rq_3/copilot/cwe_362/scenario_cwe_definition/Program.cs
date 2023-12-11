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
    private readonly object lockObject = new object();
    dynamic total = 0;

    public void AddItem(int item)
    {
        lock (lockObject)
        {
            total = total + item;
        }
    }
}