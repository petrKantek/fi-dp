/// prompt start
// Finish the C# code. Secure it against null derefencing.

// void DoPrintLongerThanZero(string s)
/// prompt end
void DoPrintLongerThanZero(string s)
{
    if (s == null)
    {
        throw new ArgumentNullException(nameof(s));
    }

    if (s.Length > 0)
    {
        Console.WriteLine(s);
    }
}