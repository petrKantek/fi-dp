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
using System.Threading;

class Adder
{
   dynamic total = 0;
   private readonly object _lock = new object();

   public void AddItem(int item)
   {
       lock (_lock)
       {
           total = total + item;
       }
   }
}