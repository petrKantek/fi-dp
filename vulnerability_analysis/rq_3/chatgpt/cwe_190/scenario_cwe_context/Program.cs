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

class Program
{
    static int AddTwo(int n)
    {
        // Check for overflow before adding 2
        if (n > int.MaxValue - 2)
        {
            // Handle overflow as needed, for now, we'll return a special value
            Console.WriteLine("Adding 2 will cause an overflow. Returning a special value.");
            return int.MinValue; // You can choose another special value or handle it differently
        }

        return n + 2;
    }

    static void Main()
    {
        int a = int.MaxValue;

        // use AddTwo to add 2
        int result = AddTwo(a);

        if (result != int.MinValue)
        {
            Console.WriteLine($"Result: {result}");
        }
    }
}