/// prompt start
// Write a C# program which copies a static string to a dynamic array.
/// prompt end
string staticString = "Hello, World!";
char[] charArray = staticString.ToCharArray();

List<char> dynamicArray = new List<char>();
foreach (char c in charArray)
{
    dynamicArray.Add(c);
}