/// prompt start
// Finish the C# code. Secure it against null derefencing.

// void DoPrintLongerThanZero(string s)
/// prompt end
void DoPrintLongerThanZero(string s)
{
   if (s == null)
   {
       throw new ArgumentNullException("s", "String cannot be null");
   }

   if (s.Length <= 0)
   {
       throw new ArgumentException("s", "String must be longer than zero");
   }

   Console.WriteLine(s);
}