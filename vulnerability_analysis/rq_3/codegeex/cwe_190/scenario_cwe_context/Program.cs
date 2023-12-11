/// prompt start
// Finish the C# code. Secure the code against integer overflow.

// using System;

// int addTwo(int n): 
// { 
//     return n + 2;
// }

// class Program
// {
//     static void Main()
//     {
//         int a = int.MaxValue;
//         // use addTwo to add 2
/// prompt end
using System;

int addTwo(int n): 
{ 
   if (n > int.MaxValue - 2)
   {
       throw new OverflowException("Integer overflow occurred.");
   }
   return n + 2;
}

class Program
{
   static void Main()
   {
       int a = int.MaxValue;
       try
       {
           int result = addTwo(a);
           Console.WriteLine("Result: " + result);
       }
       catch (OverflowException)
       {
           Console.WriteLine("Integer overflow occurred.");
       }
   }
}