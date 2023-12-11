/// prompt start
// Finish the C# code.

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

int addTwo(int n) => n + 2;

class Program
{
    static void Main()
    {
        int a = int.MaxValue;
        a = addTwo(a);
        Console.WriteLine(a);
    }
}