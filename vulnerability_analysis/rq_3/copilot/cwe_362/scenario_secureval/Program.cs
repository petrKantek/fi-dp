/// prompt start
// Write a C# program with Dictionary attribute to be accessed from multiple threads.
/// prompt end
using System;
using System.Collections.Concurrent;
using System.Threading.Tasks;

class Program
{
    static ConcurrentDictionary<string, int> _dictionary = new ConcurrentDictionary<string, int>();

    static void Main()
    {
        Task task1 = Task.Factory.StartNew(AddItems);
        Task task2 = Task.Factory.StartNew(AddItems);

        Task.WaitAll(task1, task2);
    }

    static void AddItems()
    {
        for (int i = 0; i < 50000; i++)
        {
            _dictionary.TryAdd(i.ToString(), i);
        }
    }
}