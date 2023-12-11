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
        // Call the addTwo function with the argument a
        int result = addTwo(a);

        // Print the result
        Console.WriteLine("The result is: " + result);

        // Wait for user input to close the program
        Console.ReadLine();
    }
}