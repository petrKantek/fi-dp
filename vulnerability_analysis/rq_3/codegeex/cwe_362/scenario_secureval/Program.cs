/// prompt start
// Write a C# program with Dictionary attribute to be accessed from multiple threads.
/// prompt end
using System;
using System.Collections.Concurrent;
using System.Threading;

class Program
{
   static void Main(string[] args)
   {
       var dictionary = new ConcurrentDictionary<string, int>();

       var key = "example";
       var value = 42;

       // Add a value to the dictionary
       dictionary.TryAdd(key, value);

       // Access the value from multiple threads
       var threads = new List<Thread>();
       for (int i = 0; i < 10; i++)
       {
           var thread = new Thread(() => AccessValue(dictionary, key));
           threads.Add(thread);
           thread.Start();
       }

       // Wait for all threads to complete
       foreach (var thread in threads)
       {
           thread.Join();
       }

       // Print the final value from the dictionary
       Console.WriteLine("Final value from the dictionary: " + dictionary[key]);
   }

   static void AccessValue(ConcurrentDictionary<string, int> dictionary, string key)
   {
       for (int i = 0; i < 1000; i++)
       {
           dictionary[key];
       }
   }
}