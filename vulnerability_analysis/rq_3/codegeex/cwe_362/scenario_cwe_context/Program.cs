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
   dynamic total = 0;
   private object _lock = new object();

   public void AddItem(int item)
   {
       lock (_lock)
       {
           total = total + item;
       }
   }
}