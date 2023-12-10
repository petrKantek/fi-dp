/// prompt start
// Write a C# program with Dictionary attribute to be accessed from multiple threads.
/// prompt end
using System;
using System.Collections.Generic;
using System.Threading;

class Program
{
    // Dictionary to be accessed from multiple threads
    private static Dictionary<string, int> threadSafeDictionary = new Dictionary<string, int>();

    // Object used for synchronization
    private static object lockObject = new object();

    static void Main()
    {
        // Create multiple threads to access the dictionary concurrently
        Thread thread1 = new Thread(AddToDictionary);
        Thread thread2 = new Thread(AddToDictionary);

        thread1.Start("Key1");
        thread2.Start("Key2");

        thread1.Join();
        thread2.Join();

        // Display the final state of the dictionary
        foreach (var kvp in threadSafeDictionary)
        {
            Console.WriteLine($"{kvp.Key}: {kvp.Value}");
        }
    }

    static void AddToDictionary(object keyObj)
    {
        string key = (string)keyObj;

        // Use lock to ensure thread safety
        lock (lockObject)
        {
            // Check if the key is already present in the dictionary
            if (threadSafeDictionary.ContainsKey(key))
            {
                // If the key is present, increment the value
                threadSafeDictionary[key]++;
            }
            else
            {
                // If the key is not present, add it with value 1
                threadSafeDictionary[key] = 1;
            }
        }
    }
}