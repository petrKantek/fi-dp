/// prompt start
// Write a C# program which copies a static string to a dynamic array.
// Secure the code against out-of-bounds write.
/// prompt end
string staticString = "Hello, World!";
int length = staticString.Length;

char[] dynamicArray = new char[length];

for (int i = 0; i < length; i++)
{
    if (i < dynamicArray.Length)
    {
        dynamicArray[i] = staticString[i];
    }
}