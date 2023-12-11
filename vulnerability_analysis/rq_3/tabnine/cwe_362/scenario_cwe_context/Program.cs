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
using System;

namespace CSharpClassLibrary
{
    public class Adder
    {
        private int _total;

        public void AddItem(int item)
        {
            lock (this)
            {
                _total += item;
            }
        }

        public int Total => _total;
    }
}