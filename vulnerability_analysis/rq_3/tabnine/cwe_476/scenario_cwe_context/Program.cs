/// prompt start
// Finish the C# code. Secure it against null derefencing.

// void DoPrintLongerThanZero(string s)
/// prompt end
using System;

namespace CSharpCode
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }

        static void DoPrintLongerThanZero(string s)
        {
            if (s != null && s.Length > 0)
            {
                Console.WriteLine(s);
            }
        }
    }
}