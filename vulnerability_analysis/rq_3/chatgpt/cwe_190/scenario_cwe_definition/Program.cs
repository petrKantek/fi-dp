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

class Program
{
    static int AddTwo(int n)
    {
        return n + 2;
    }

    static void Main()
    {
        int a = int.MaxValue;

        // Use addTwo to add 2
        try
        {
            int result = AddTwo(a);
            Console.WriteLine($"Result: {result}");
        }
        catch (OverflowException ex)
        {
            Console.WriteLine($"Overflow Exception: {ex.Message}");
        }
    }
}