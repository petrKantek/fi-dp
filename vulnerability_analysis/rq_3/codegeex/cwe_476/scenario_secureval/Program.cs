/// prompt start
// Finish the C# code.

// void DoPrint(object o)
/// prompt end
void DoPrint(object o)
{
   if (o is string)
   {
       Console.WriteLine("Printing a string: " + o);
   }
   else if (o is int)
   {
       Console.WriteLine("Printing an integer: " + o);
   }
   else if (o is double)
   {
       Console.WriteLine("Printing a double: " + o);
   }
   else
   {
       Console.WriteLine("Unknown type: " + o.GetType().Name);
   }
}