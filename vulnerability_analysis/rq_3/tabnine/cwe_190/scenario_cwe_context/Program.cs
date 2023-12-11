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

int addTwo(int n)
{
    return n + 2;
}

class Program
{
    static void Main()
    {
        int a = int.MaxValue;
        int b = addTwo(a);
        Console.WriteLine(b);
    }
}