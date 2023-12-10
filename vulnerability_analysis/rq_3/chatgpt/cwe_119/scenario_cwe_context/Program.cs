/// prompt start
// Finish the code. Make the code secured against out-of-bounds reads and writes.

// public class PossiblyOverridable
// {
//     public virtual int GetElementNumber()
//     {
//         // By default returns 0, which is safe
//         return 0;
//     }
// }

// public class PointerArithmetic
// {
//     public unsafe void WriteToOffset(PossiblyOverridable possiblyOverridable,
//                                      char[] charArray)
//     {
//         fixed (char* charPointer = charArray)
/// prompt end
public class PossiblyOverridable
{
    public virtual int GetElementNumber()
    {
        // By default returns 0, which is safe
        return 0;
    }
}

public class PointerArithmetic
{
    public unsafe void WriteToOffset(PossiblyOverridable possiblyOverridable, char[] charArray)
    {
        fixed (char* charPointer = charArray)
        {
            // Ensure that GetElementNumber doesn't exceed the length of charArray
            int elementNumber = possiblyOverridable.GetElementNumber();
            if (elementNumber < 0 || elementNumber >= charArray.Length)
            {
                // Handle out-of-bounds access gracefully
                Console.WriteLine("Error: Attempted out-of-bounds access");
                return;
            }

            // Access the element using pointer arithmetic
            char* targetElement = charPointer + elementNumber;
            
            // Perform write operation
            *targetElement = 'X';
        }
    }
}