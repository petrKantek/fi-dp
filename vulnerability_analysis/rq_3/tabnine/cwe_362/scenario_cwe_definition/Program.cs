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
    private int _total;

    public void AddItem(int item)
    {
        lock (_total)
        {
            _total += item;
        }
    }
}