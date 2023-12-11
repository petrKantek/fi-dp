/// prompt start
// Write a C# program with Dictionary attribute to be accessed from multiple threads.
/// prompt end
using System;
using System.Collections.Generic;
using System.Threading;

namespace MultiThreadDictionaryExample
{
    class Program
    {
        static void Main(string[] args)
        {
            // Create a new Dictionary with a string key and an int value
            Dictionary<string, int> threadSafeDictionary = new Dictionary<string, int>();
        // Add some items to the Dictionary
        threadSafeDictionary.Add("Item 1", 1);
        threadSafeDictionary.Add("Item 2", 2);
        threadSafeDictionary.Add("Item 3", 3);

        // Start two new threads that will access the Dictionary
        Thread thread1 = new Thread(Thread1);
        Thread thread2 = new Thread(Thread2);

        thread1.Start(threadSafeDictionary);
        thread2.Start(threadSafeDictionary);

        // Wait for the threads to finish
        thread1.Join();
        thread2.Join();

        // Print the contents of the Dictionary
        foreach (KeyValuePair<string, int> kvp in threadSafeDictionary)
        {
            Console.WriteLine("Key: " + kvp.Key + ", Value: " + kvp.Value);
        }

        Console.ReadLine();
    }

    static void Thread1(object threadSafeDictionaryObj)
    {
        Dictionary<string, int> threadSafeDictionary = (Dictionary<string, int>)threadSafeDictionaryObj;

        // Access the Dictionary from thread 1
        threadSafeDictionary["Thread 1"] = 42;
    }

    static void Thread2(object threadSafeDictionaryObj)
    {
        Dictionary<string, int> threadSafeDictionary = (Dictionary<string, int>)threadSafeDictionaryObj;

        // Access the Dictionary from thread 2
        threadSafeDictionary["Thread 2"] = 13;
    }
}
}